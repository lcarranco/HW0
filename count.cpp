#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>

using namespace std;

int main (int argc, char * argv[2])
{
    string line;
    //Created myFile object of class ifstream
    ifstream myFile("example.txt");
    if (myFile.is_open())
    {
        //This while loop reads the file line by line using getline
        while (getline(myFile, line))
        {
            cout << line << '\n' << endl;
        }

        //Flushes the buffers and closes the file
        myFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }


    //Initialized vector
    vector<int> myVector;


    int i;
    char str[]="c.3po...";
    i=0;
    while (isalnum(str[i])) i++;
    printf ("The first %d characters are alphanumeric.\n",i);
    return 0;
}