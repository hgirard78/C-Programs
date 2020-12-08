#include <stdio.h>
#include <string.h>

size_t size(char s[]){
    size_t i = 0;
    while (s[i] != 0)
        i++;
    return i;
}

void mix_one(char s[], size_t size_s)
{
    if (size_s <= 3)
        return;
    else
    {
        for (size_t i = 1; i < size_s - 2; i+=2){
            char temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
    }
}

int isSeparator(char *c)
{
    char separator[] = " ,;:!?./%*$=+)@_-('&1234567890\"\r\n";
    size_t size_separator = size(separator);
    for (size_t i = 0; i < size_separator; i++)
    {
        if (*c == separator[i])
            return 1;
    }
    return 0;
}



void mix(char s[]){

    size_t size_s = size(s);
    size_t i = 0;
    while (i < size_s)
    {
        char temp[size_s];
        size_t j = 0;
        size_t index = i;
        while (isSeparator(&s[i]) == 0)
        {
            temp[j] = s[i];
            i++;
            j++;
        }
        while (temp[j] != 0 && j < size(temp))
        {
            temp[j] = 0;
            j++;
        }
        size_t size_temp = size(temp);
        if (size_temp > 3)
        {
            mix_one(temp, size_temp);
            size_t k = 0;
            while (index < i){
                s[index] = temp[k];
                index++;
                k++;
            }
        }
        i++;
    }
}

