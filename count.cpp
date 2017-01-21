#include <stdio.h>
#include <iostream>
#include <cctype>

using namespace std;

int main (int argc, char * argv[2])
{
    int i;
    char str[]="c3po...";
    i=0;
    while (isalnum(str[i])) i++;
    printf ("The first %d characters are alphanumeric.\n",i);
    return 0;
}