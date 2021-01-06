#include <err.h>
#include "vector.h"

struct vector *vector_new()
{
    struct vector *vector = malloc(sizeof(struct vector));
    int *data = malloc(sizeof(int));
    if (vector == NULL || data == NULL)
    {
        errx(1, "Not enough memory!");
    }
    vector->capacity = 1;
    vector->size = 0;
    vector->data = data;
    return vector;
}

void vector_free(struct vector *v)
{
    free(v->data);
    free(v);
}

void double_capacity(struct vector *v)
{
    v = realloc(v, 2 * sizeof(v));
    if (v == NULL)
    {
        errx(1, "Not enough memory!");
    }
    v->capacity = 2 * v->capacity;
}

void vector_push(struct vector *v, int x)
{
    if (v->size == v->capacity)
        double_capacity(v);
    int *data = v->data;
    *(data + v->size) = x;
    v->size += 1;
}

int vector_pop(struct vector *v, int *x)
{
    if (v->size != 0)
    {
        *x = *(v->data + v->size-1);
        *(v->data + v->size-1) = 0;
        v->size--;
        return 1;
    }
    
    return 0;
}

int vector_get(struct vector *v, size_t i, int *x)
{
    if (i > v->size-1)
        return 0;
    *x = *(v->data + i);
    return 1;
}

void vector_insert(struct vector *v, size_t i, int x)
{
    if (i > v->size)
        return;
    if (v->size == v->capacity)
        double_capacity(v);
    for (size_t j = v->size; j > i; j--)
    {
        *(v->data + j) = *(v->data + j - 1);
    }
    v->size++;
    *(v->data + i) = x;
}

int vector_remove(struct vector *v, size_t i, int *x)
{
    if (i > v->size)
        return 0;
    *x = *(v->data + i);
    for (size_t j = i; j < v->size; j++)
    {
        *(v->data + j) = *(v->data + j + 1);
    }
    v->size--;
    return 1;
}
