#include <stdio.h>
#include "mix.h"
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        printf("%s\n", argv[1]);
        mix(argv[1]);
        printf("%s", argv[1]);
    }
    else
    {
        char default_text[] = "la prog c'est NULL!";
        mix(default_text);
        printf("%s\n", default_text);
        mix(default_text);
        printf("%s", default_text);
    }
    return 0;
}
