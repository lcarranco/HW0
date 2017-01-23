#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "readFile.h"

void ReadFile::readFile()
{
    std::string line;
    //Created myFile object of class ifstream
    std::ifstream myFile("example.txt");
    if (myFile.is_open())
    {
        //This while loop reads the file line by line using getline
        while (std::getline(myFile, line))
        {
            std::cout << line << '\n' << std::endl;
        }

        //Flushes the buffers and closes the file
        myFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}