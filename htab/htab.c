
#include <err.h>
#include <stdio.h>
#include <string.h>

#include "htab.h"

uint32_t hash(char *key)
{
size_t i = 0;
uint32_t hash = 0;
while(*(key+i) != 0)
{
hash += *(key+i);
hash += hash << 10;
hash ^= hash >> 6;
i += 1;
}
hash += hash << 3;
hash ^= hash >> 11;
hash += hash << 15;
return hash;
}

struct htab *htab_new()
{
  struct htab *table = malloc(sizeof(struct htab));
  if(table == NULL)
    {
      errx(1, "Not enough memory!");
    }
  table->size = 0;
  table->capacity = 4;
  struct pair *dat = malloc(sizeof(struct pair)*table->capacity);
  if(dat == NULL)
    {
      errx(1, "Not enough memory!");
    }
  for(size_t i = 0; i<table->capacity;i++)
    {
      (dat + i)->hkey = 0;
      (dat+i)->key = NULL;
      (dat+i)->value = NULL;
      (dat+i)->next = NULL;
    }
  table->data = dat;
  return table;
 
}

void clear_pairs(struct pair *p)
{
  if(p->next != NULL)
    {
      clear_pairs(p->next);
      free(p->next);
    }
}

void htab_clear(struct htab *ht)
{
    struct pair *p = ht->data;
    for(size_t i =0; i<ht->capacity; i++)
    {
   clear_pairs(p+i);
    }
    ht->size = 0;
}

void htab_free(struct htab *ht)
{
  htab_clear(ht);
  //struct pair *p = ht->data;
  /*for(size_t i =0; i<ht->capacity; i++)
    {
      free(p+i);
      }*/
  free(ht->data);
  free(ht);
}

struct pair *htab_get(struct htab *ht, char *key)
{
  uint32_t hh = hash(key);
  size_t i = hh % ht->capacity;
  struct pair *p = ht->data + i;
  while(p != NULL && p->key != key && p->hkey != hh)
    {
      p = p->next;
    }
  return p;
}

struct htab * double_hash_cap(struct htab *ht)
{
  struct pair *l = malloc(sizeof(struct pair));
  struct pair *li = l;
  l->value = NULL;
  l->hkey = 0;
  l->key = NULL;
  l->next = NULL;

  
  for(size_t i = 0; i < ht->capacity; i ++)
    {
      struct pair *p = ht->data + i;
      struct pair *pi = p->next;
      while(pi != NULL)
	{
	  li->next = pi;
	  li = pi;
	  pi = pi->next;
	}
      p->next = NULL;
    }

  ht->capacity = ht->capacity * 2;
  ht->size = 0;
  ht->data = realloc(ht->data,sizeof(struct pair) * ht->capacity);

  for(size_t i = ht->capacity / 2; i < ht->capacity; i ++)
    {
      (ht->data + i)->hkey = 0;
      (ht->data+i)->key = NULL;
      (ht->data+i)->value = NULL;
      (ht->data+i)->next = NULL;
    }

  if(ht == NULL)
      errx(1, "Not enough memory!");
    
  
  li = l->next;
  while(li != NULL)
    {
      htab_insert(ht,li->key,li->value);
      li = li->next;
      }

  clear_pairs(l);
  free(l);

  return ht;
}

void add_element(struct htab *ht, char *key, void *value)
{
  uint32_t hh = hash(key);
  size_t i = hh % ht->capacity;
  struct pair *p = ht->data + i;
  if(p->next == NULL) ht->size ++;

  struct pair *pn = p->next;
  struct pair *newp = malloc(sizeof(struct pair));
  newp->key = key;
  newp->value = value;
  newp->hkey = hh;
  newp->next = pn;
  p->next = newp;

}

int htab_insert(struct htab *ht, char *key, void *value)
{
  if(htab_get(ht,key) != NULL)
    return 0;

  int ration = 100 * ht->size / ht->capacity;
  if(ration >= 75)
    {
      ht = double_hash_cap(ht);
    }

  
  
  add_element(ht,key,value);
  return 1;
}

void htab_remove(struct htab *ht, char *key)
{
    uint32_t hh = hash(key);
    size_t i = hh % ht->capacity;
    struct pair *p = ht->data + i;
    while(p->next != NULL && p->next->key != key && p->next->hkey != hh)
    {
      p = p->next;
    }

    if(p->next == NULL) return;

    struct pair *old = p->next;
    p->next = old->next;
    
    free(old);

    if(p->next == NULL) ht->size--;
}

