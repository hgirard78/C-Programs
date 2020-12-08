#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void list_init(struct list *list)
{
    list->data = 0;
    list->next = NULL;
}

int list_is_empty(struct list *list)
{
    return list->next==NULL || list==NULL;
}

size_t list_len(struct list *list)
{
    size_t len;
    for(len = 0; list; list = list->next)
    {
        len += 1;
    }
    return len - 1;
}

void list_push_front(struct list *list, struct list *elm)
{
    if (list == NULL || elm == NULL)
        return;
    elm->next = list->next;
    list->next = elm;
    return;
}

struct list *list_pop_front(struct list *list)
{
    if (list_is_empty(list))
        return NULL;
    else if (list->next != NULL)
    {
        struct list *elm = list->next;
        list->next = list->next->next;
        elm->next = NULL;
        return elm;
    }
    return NULL;
}

struct list *list_find(struct list *list, int value)
{
    for (; list; list = list->next)
    {
        if (list->data == value)
        {
            return list; 
        }
    }
    return NULL;
}

struct list *list_lower_bound(struct list *list, int value)
{
    if (list_is_empty(list))
        return list;
    struct list* l = NULL;
    for (; list; list = list->next)
    {
        l = list;
        if (list->next && list->next->data >= value)
        {
            break; 
        }
    }
    return l;
}

int list_is_sorted(struct list *list)
{
   if (list->next == NULL || list->next->next == NULL || list == NULL)
       return 1;
   list = list->next;
   while (list && list->next)
   {
        if (list->data > list->next->data)
            return 0;
        list = list->next;
   }
   return 1;
}

void list_insert(struct list *list, struct list *elm)
{
    if(list_is_empty(list))
        list_push_front(list, elm);
    else
    {
        struct list* l = list_lower_bound(list, elm->data);
        elm->next = l->next;
        l->next = elm;
    }
}

void list_rev(struct list *list)
{
    if (list_is_empty(list))
        return;
    size_t len = list_len(list);
    list = list->next;
    for (size_t iter = 0; iter < len / 2; ++iter)
    {
        struct list *current = list;
        for (size_t swp = 0; current->next && swp < len - (2 * iter) - 1; ++swp)
            current = current->next;
        int tmp = list->data;
        list->data = current->data;
        current->data = tmp;
        list = list->next;
    }
}

void list_half_split(struct list *list, struct list *second)
{
    size_t len = list_len(list);
    size_t i = 0;
    //list = list->next;
    printf("list_len : %ld\n", len);
    struct list *save = list;
    while (i < len)
    {
        if (i >= len / 2)
        {   if (i == len / 2)
                save = list;
            second->data = list->data;
            second->next = list->next;
            printf("second->data : %d\n", second->data);
            second = second->next;

        }
        list = list->next;
        i++;
    }
    save->next = NULL;

}
