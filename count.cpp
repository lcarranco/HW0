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
  vector<string> wordVector;
  while (getline(ifs, line)){
    //replace symbols by space for line.
    //...
    //Got the following code from http://stackoverflow.com/questions/7621727/split-a-string-into-words-by-multiple-delimiters
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ';\n\\~`!@#$%^&*()-_+={}[]|:<,>.?/", prev)) != std::string::npos)
    {
        if (pos > prev)
            wordVector.push_back(line.substr(prev, pos-prev));
        prev = pos+1;
    }
    if (prev < line.length()) {
        wordVector.push_back(line.substr(prev, std::string::npos));
    }
    //End of StackOverflow code
    for(int i = 0; i < wordVector.size(); i++) {
        cout << i << endl;
    }
    std::stringstream ss(line.c_str());
    std::string str;
    while (ss >> str) {
      if (is_number(str)) {
        numberCount++;
      }
      else {
        wordCount++;
      }
    }
  }
  cout << numberCount << endl;
		
  return 0;
}

bool is_number(const std::string& s)
{
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}