#include <stdio.h>
#include "helper.h"
#include "insert_sort.h"

void array_insert(int *begin, int *end, int x)
{
    while (begin != end && x < *(end - 1))
    {
        *(end) = *(end - 1);
        end--;
    }

    *end = x;
}

int binary_search(int *begin, int *end, int x)
{
    int *left = begin;
    int *right = end;
    int size = end - begin;
    int l = 0;
    int r = size;

    while (left <= right)
    {
        int *mid = left + (right - left) / 2;
        int m = l + (r - l) / 2;
        if (*mid == x)
            return m;
        if (*mid < x)
        {
            left = mid + 1;
            l = m + 1;
        }

        else
        {
            right = mid - 1;
            r = m - 1;
        }
    }
    return r+1;
}

void array_insert_bin(int *begin, int *end, int x)
{
    int i = binary_search(begin, end, x);
    int j = end - begin;
    while (j > i)
    {
        *end = *(end - 1);
        end--;
        j--;
    }
    *end = x;
}

void array_insert_sort(int *begin, int *end)
{
    int *index = begin;
    while(index < end)
    {
        array_insert(begin, index, *(index));
        index++;
    }
}

void array_insert_sort_bin(int *begin, int *end)
{
    int *index = begin;
    while (index < end)    
    {
        array_insert_bin(begin, index, *(index));
        index++;
    }
}

