#include <stdio.h>
#include <err.h>
#include <string.h>

size_t str_len(char* string)
{
    size_t i = 0;
    while (string[i] != 0)
    {
        i++;
    }
    return i;
}

int main(int argc, char **argv){
    if (argc != 3){
        printf("main: Usage: str1 str2"); 
        errx(1, "Not enough args");
    }

    char *string = argv[1];
    char *subsequence = argv[2];
    size_t size_string = str_len(string);
    size_t size_sub = str_len(subsequence);
    size_t i = 0;
    size_t j = 0;
    int index = 0;
    while (i < size_string && j < size_sub){
        j = 0; 
        while (i < size_string && string[i] != subsequence[j])
            i++;
        index = i;
        while (i < size_string && j < size_sub){
            if (string[i] == subsequence[j]){
                i++;
                j++;

            }
            else
                break;
        }
    }

    if (j == size_sub)
    {
        printf("%s\n", string);
        for (int l = 0; l < index; l++){
            printf(" ");
        }
        printf("^");
    }
    else
        printf("Not found");
    return 0;
}
