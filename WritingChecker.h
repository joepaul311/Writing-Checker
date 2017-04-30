#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

#define SIZE 6
using namespace std;

class WritingChecker {
 private:
  vector<string> errorCatalogue;
  vector<vector<string> > writing;
  unordered_map<string, int> frequencyTable;
  bool features[SIZE];
  string fileName;

  string stripWord(string);
  bool checkPrepositionEnd(int, int, string);
  int* checkWord(int,int);
  bool checkPassive(string, int, int);
  void addToHash(string);
  bool checkEndSentence(string);
  bool checkFirstPerson(int,int,string);
  bool checkSecondPerson(int,int,string);
  bool checkFluff(string);
  bool checkContraction(string);
 public:
  WritingChecker(string, bool[]);
  void analyze();
  string writingStringify();


};






