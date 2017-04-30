#include <iostream>
#include <string>
#include <vector>
#include "WritingChecker.h"
#include <fstream>
#define SIZE 6
using namespace std;

int main()
{

  bool options[SIZE];
  for(int i = 0; i < SIZE; i++) {
    options[i] = true;
 
 
 
  }
  WritingChecker wCheck("book.txt",options);
  wCheck.analyze();
  cout<< wCheck.writingStringify();

	return 0;
}
