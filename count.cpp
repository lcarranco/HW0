#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

bool is_number(const std::string& s);

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "Usage: count filename=input1.txt\n";
  }
  ArgumentManager am(argc, argv);
  std::string filename = am.get("filename");
  std::ifstream ifs(filename.c_str());
  std::string line;
  int wordCount = 0, numberCount = 0;
  char c = ' ';
  clock_t startClock; //Initialized a variable of type clock
  startClock = clock(); 
  while (getline(ifs, line)){
    //replace symbols by space for line.
    for (char &x : line) //Created a character x to traverse through the document line by line
    {
      if (!isalnum(x)) //The isalnum function checks each character in the document is either a decimal digit or an uppercase or lowercase letter. The function returns a value different from zero if it is indeed a digit or a letter. Function returns a zero otherwise. The if conditional is checking to see if the character is not a digit or letter then replace that character with a space.
      {
        x = ' '; //Replacing the character with a space.
      }
    }
    std::stringstream ss(line.c_str());
    std::string str;
    while (ss >> str) {
      if (is_number(str))
      {
        numberCount++;
      }
      else
      {
        wordCount++;
      }
    }
  }
  startClock = clock() - startClock;
  cout << startClock << endl;
  cout << "words=" << wordCount << " numbers=" << numberCount << endl;
  return 0;
}

bool is_number(const std::string& s)
{
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}