#include <err.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"

uint32_t hash(char *key)
{
    size_t len = strlen(key);
    size_t i = 0;
    uint32_t hashkey = 0;

    while (i != len)
    {
        hashkey += key[i++];
        hashkey += hashkey << 10;
        hashkey ^= hashkey >> 6;
    }

    hashkey += hashkey << 3;
    hashkey ^= hashkey >> 11;
    hashkey += hashkey << 15;

    return hashkey;
}

struct htab *htab_new()
{
    struct htab *hashtab = malloc(sizeof(struct htab));

    if (hashtab == NULL) 
    {
        errx(1, "Not enough memory!");
    }

    hashtab->capacity = 4;
    hashtab->size = 0;

    struct pair *data = calloc(hashtab->capacity, sizeof(struct pair));

    if (data == NULL)
        errx(1, "Not enough memory!");

    hashtab->data = data;

    return hashtab;
}

void htab_clear(struct htab *ht)
{
    ht->size = 0;
    struct pair *stock;
    struct pair *stock1;

    for (size_t i = 0; i < ht->capacity; i++)
    {
        stock = ht->data[i].next;

        while (stock)
        {
            stock1 = stock->next; 
            free(stock);
            stock = stock1;
        }

        ht->data[i].next = NULL;
    }
}

void htab_free(struct htab *ht)
{
    htab_clear(ht);
    free(ht->data);
    free(ht);
}

struct pair *htab_get(struct htab *ht, char *key)
{
    uint32_t hashkey = hash(key);
    int i = hashkey % (ht->capacity);
    struct pair *data = ht->data[i].next;

    while (data)
    {
        if (data->key == key) 
            return data;

        data = data->next;
    }

    return NULL;
}

int htab_insert(struct htab *ht, char *key, void *value)
{
    uint32_t hkey = hash(key);
    size_t index = hkey % (ht->capacity);
    struct pair *x = ht->data[index].next;
    
    struct pair *p = malloc(sizeof(struct pair));
    p->hkey = hkey;
    p->key = key;
    p->value = value;

    while (x)
    {
        if (x->key == key)
            return 0;
        x = x->next;
    }

    x = &(ht->data[index]);
    if (x->next)
    {
        x = x->next;
        p->next = x;
        ht->data[index].next = p;
    }
    else
    { 
        p->next = NULL; 
        ht->data[index].next = p;
        ht->size++;
    }
    int ratio = 100 * (ht->size) / (ht->capacity);
    if (ratio > 75)
    {
        size_t old_cap = ht->capacity;
        ht->capacity *= 2;
        size_t size = 0;
        struct pair *data = calloc(ht->capacity, sizeof(struct pair));

        if (data == NULL)
        {
            errx(1, "Not enough memory!");
        }

        for (size_t i = 0; i < old_cap; i++)
        {
            struct pair *p = ht->data[i].next;

            while (p)
            {
                struct pair *save = p->next;
                struct pair *stock = p;
                size_t index = (stock->hkey) % (ht->capacity);
                struct pair *pdata = &data[index];

                if (pdata->next)
                {
                    pdata = pdata->next;
                    stock->next = pdata;
                    data[index].next = stock;
                }

                else
                {
                    stock->next = NULL;
                    pdata->next = stock;
                    size++;
                }

                p = save;
            }
        }

        free(ht->data);
        ht->data = data;
        ht->size = size;
    }

    return 1;
}

void htab_remove(struct htab *ht, char *key)
{
    if (htab_get(ht, key) == NULL)
        return;

    uint32_t hkey = hash(key);
    size_t index = hkey % (ht->capacity);
    struct pair *p = &(ht->data[index]);
    if (p->next->next == NULL)
    {
        ht->size--;
    }

    while (p->next)
    {
        if (p->next->key == key)
        {
            struct pair *stock = p->next;

            if (stock->next)
            {
                p->next = p->next->next;
                free(stock);
            }

            else
            {
                p->next = NULL;
                free(stock);
            }
        }

        if (p->next)
            p = p->next;
    }
}
