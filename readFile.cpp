#include <stdio.h>
#include <iostream>
#include <fstream>
#include "readFile.h"

void ReadFile::readFile()
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
}