#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

int main (int argc, char * argv[2])
{
    vector<int> vector1(10, 5);
    for (size_t i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << endl; // Printing out a vector that is size 10 that is initialized to the value of 5
    }
    int i;
    char str[]="c.3po...";
    i=0;
    while (isalnum(str[i])) i++;
    printf ("The first %d characters are alphanumeric.\n",i);
    return 0;
}