#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include "readFile.h"

using namespace std;

int main (int argc, char * argv[2])
{
    ReadFile a;
    a.readFile();

    //Initialized vector
    vector<int> myVector;


    int i;
    char str[]="c.3po...";
    i=0;
    while (isalnum(str[i])) i++;
    printf ("The first %d characters are alphanumeric.\n",i);
    return 0;
}