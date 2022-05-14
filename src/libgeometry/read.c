#include "read.h"
#include <stdio.h>

void* inputString(char* str)
{
    fgets(str, 50, stdin);
    return NULL;
}
