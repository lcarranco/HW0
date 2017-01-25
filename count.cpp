#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include "readFile.h"
#include "ArgumentManager.h"

using namespace std;

//Copied from https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
template <class T>
class Stack { 
   private: 
      vector<T> elems;     // elements 

   public: 
      void push(T const&);  // push element 
      void pop();               // pop element 
      T top() const;            // return top element 
      bool empty() const{       // return true if empty.
         return elems.empty(); 
      } 
};

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
  int wordCount = 0, numberCount;
  char c = ' ';
  while (getline(ifs, line)){
    //replace symbols by space for line.
    //...
    for (char &x : line)
    {
      if (!isalnum(x))
      {
        x = ' ';
        //cout << line << endl;
      }
    }
    std::stringstream ss(line.c_str());
    std::string str;
    while (ss >> str) {
      cout << str << endl;
    }
  }
		
  return 0;
}

bool is_number(const std::string& s)
{
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}