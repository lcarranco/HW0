#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include "readFile.h"
#include "ArgumentManager.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "Usage: count filename=input1.txt\n";
  }
  ArgumentManager am(argc, argv);
  std::string filename = am.get("filename");
  std::ifstream ifs(filename.c_str());
  std::string line;
  while (getline(ifs, line)){
    // replace symbols by space for line.
    // ...
    std::stringstream ss(line.c_str());
    std::string str;
    while (ss >> str) {
      if (is_number(str)) {
	// ...
      }
      else {
      // ...
      }
    }
  }
		
  return 0;
}