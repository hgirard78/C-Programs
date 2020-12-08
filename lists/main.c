#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(struct list *list)
{
    printf("list_is_empty() = %s\n", list_is_empty(list) ? "yes" : "no");
    printf("list_is_sorted() = %s\n", list_is_sorted(list) ? "yes" :  "no");
    printf("list_len() = %zu\n", list_len(list));

    int line = 1;

    printf("[");
    if (list->next)
    {
        goto pastfst;
        while (list->next)
        {
            line += printf(";");

            if (line > 72)
            {
                printf("\n ");
                line = 1;
            }

            pastfst:
            line += printf(" %2d", list->next->data);
            list = list->next;
        }
    }

    printf(" ]\n");
}

void list_insert_sort(struct list *list)
{
    if (list_is_empty(list))
        return;

    struct list fake_head = { 0, 0 };

    while (!list_is_empty(list))
    {
        struct list *elm = list_pop_front(list);
        list_insert(&fake_head, elm);
    }

    list->next = fake_head.next;
}

int main()
{
    /*struct list *list = malloc(sizeof(*list));
    list_init(list);
    print_list(list);
    struct list elm = {NULL, 15};
    //list_push_front(list, &elm);
    //struct list elm2 = {NULL, 10};
    //list_push_front(list, &elm2);
    struct list elm3 = {NULL, 5};
    list_push_front(list, &elm3);
    print_list(list);
    //printf("list_pop_front : %d\n", list_pop_front(list)->data);
    //list_push_front(list, &elm3);
    //printf("list_find 5 : %d\n", list_find(list, 5)->data);
    //printf("list_lower_bound 4: %d\n", list_lower_bound(list, 4)->data);
    //print_list(list);
    struct list elm4 = {NULL, 12};
    list_insert(list, &elm4);
    print_list(list);
    list_rev(list);
    print_list(list);
    return 0;*/
    struct list *list = malloc(sizeof(*list));
    list_init(list);
    print_list(list);
    
    struct list elm = {NULL, 15};
    list_push_front(list, &elm);
    print_list(list);
    
    struct list elm2 = {NULL, 10};
    list_push_front(list, &elm2);
    struct list elm3 = {NULL, 5};
    list_push_front(list, &elm3);
    print_list(list);
/*
    printf("pop : %d\n", list_pop_front(list)->data);
    print_list(list);

    printf("pop : %d\n", list_pop_front(list)->data);
    print_list(list);
*/
    printf("find 10: %d\n", list_find(list, 10)->data);
    printf("find 5: %d\n", list_find(list, 5)->data);

    struct list in = { NULL, 7};
    struct list in2 = { NULL, 14};
    struct list in3 = { NULL, 2};
    list_insert(list, &in);
    list_insert(list, &in2);
    list_insert(list, &in3);
    print_list(list);

    printf("REVERSE :\n");
    list_rev(list);
    struct list elm5 = {NULL, 16};
    list_push_front(list, &elm5);
    print_list(list);

    struct list *second = malloc(sizeof(*list));
    list_init(second);
    printf("Half-Split\n");
    list_half_split(list, second);
    printf("FIRST\n");
    print_list(list);
    printf("SECOND\n");
    print_list(second);
    return 0;
}
