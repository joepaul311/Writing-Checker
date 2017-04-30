#include "WritingChecker.h"
#include "Tables.h"

#define PASSIVE 0
#define FIRST_PERSON 1
#define SECOND_PERSON 2
#define FLUFF 3
#define CONTRACTION 4
#define PREPOSITION_ENDING 5

#define SIZE 6

bool WritingChecker :: checkPassive(string word, int sentenceIndex, int wordIndex) {
  if(preposition.count(word) == 1) {
    //if the current word has at least two before it, and there is a passive word two words before it, return true;
    if(wordIndex > 1 && toBe.count(stripWord(writing[sentenceIndex][wordIndex - 2]))) { 
      return true;
    }
  }

  return false;
}
bool WritingChecker :: checkEndSentence(string word) {
  char punctuation = word[word.length() - 1];
  if(punctuation == '.' || punctuation == '?' || punctuation == '!') {
    return true;
  }
  if(word.length() > 1) {
    char p2 = word[word.length() - 2];
    if(punctuation == '"' || punctuation == '\''){ 
      if(p2 == '.' || p2 == '?' || p2 == '!') {
	return true;
      }
    }
  }

  return false;
  
}
bool WritingChecker :: checkPrepositionEnd(int sentenceIndex, int wordIndex, string word) {
  return preposition.count(word) == 1 && writing[sentenceIndex].size() == wordIndex+1 && checkEndSentence(writing[sentenceIndex][wordIndex]);
}

int*  WritingChecker::checkWord(int sentence, int word)
{
  string stripped = stripWord(writing[sentence][word]);
  addToHash(stripped);
  int* tFeatures = new int[SIZE];
 
  for(int i = 0; i < SIZE; i++) {
    tFeatures[i] = 0;
  }
  
  /*
    {words: [[]], errors: [{index: [-1,-1], message: "dicks", word=""}]}
   */
  string i = to_string(sentence);
  string j = to_string(word);
  if (features[PASSIVE]) {
    if(checkPassive(stripped, sentence, word)) {
      errorCatalogue.push_back("{\"index\": [" + i + ", " + j + "], \"message\": \"You used the passive voice.\", \"word\" : \"\"}");
      tFeatures[PASSIVE] = 1;
    }
  }
  
  if (features[FIRST_PERSON]) {
   if(checkFirstPerson(sentence, word, stripped)) {
     errorCatalogue.push_back("{\"index\": [" + i + ", " + j + "], \"message\": \"You used first person.\", \"word\" : \"\"}");
     tFeatures[FIRST_PERSON] = 1;
   }
  }
  if (features[SECOND_PERSON]) {
    if(checkSecondPerson(sentence, word, stripped)) {
      errorCatalogue.push_back("{\"index\": [" + i + ", " + j + "], \"message\": \"You used second person.\", \"word\" : \"\"}");
      tFeatures[SECOND_PERSON] = 1;
    }
  }
  
  if (features[FLUFF]) {
    if(checkFluff(stripped)) {
      errorCatalogue.push_back("{\"index\": [" + i + ", " + j + "], \"message\": \"You used extraneous words.\", \"word\" : \"" + writing[sentence][word] + "\"}");
     tFeatures[FLUFF] = 1;
    }
  }
  if(features[CONTRACTION]) {
    if(checkContraction(stripped)) {
      errorCatalogue.push_back("{\"index\": [" + i + ", " +j + "], \"message\": \"You used a contraction.\", \"word\" : \"\"}");
      tFeatures[CONTRACTION] = 1;
    }
  }
  if(features[PREPOSITION_ENDING]) {
    if(checkPrepositionEnd(sentence, word, stripped)) {
      errorCatalogue.push_back("{\"index\": [" + i + ", " +j + "], \"message\": \"You used extraneous words.\", \"word\" : \"\"}");
      tFeatures[PREPOSITION_ENDING] = 1;
    }
  }
  return tFeatures;
}




void WritingChecker :: analyze(){

  ifstream in(fileName.c_str());
  streambuf *cinbuf = std::cin.rdbuf(); //save old buf                                                                                                                                                
  cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!                                                                                                                                              
              
  int numSentences = 0;
  int numWords = 0;
  string word;
  vector<string> sentence;
  int tResult[SIZE]; //keep tracks of checkWord's results.
 
  for(int i =0; i < SIZE; i++) {
    tResult[i] = 0;
  }
 
  writing.push_back(sentence);
  while(cin>>word) {
    writing[numSentences].push_back(word);
   
    int* temp;
    
    temp = checkWord(numSentences, numWords);
    
    for(int i = 0; i < SIZE; i++) {
      tResult[i] += temp[i];
    }
    
    numWords++;
    
    if(checkEndSentence(word)) {
      bool hasError = false;
      string errorMSG = "[";
      
      if(tResult[PASSIVE]) {
	if(!hasError) {
	  hasError = true;
	}
	errorMSG = "[DETECTED: PASSIVE VOICE";
      }
      
      if(tResult[FIRST_PERSON]) {
	if(!hasError) {
	  hasError = true;
	  errorMSG = "[DETECTED: FIRST PERSON USE";
	}
	else {
	  errorMSG += ", FIRST PERSON USE";
	}
      }
      
      if(tResult[SECOND_PERSON]) {
	if(!hasError) {
	  hasError = true;
	  errorMSG = "[DETECTED: SECOND PERSON USE";
	}
	else {
	  errorMSG += ", SECOND PERSON USE";
	}
      }
      
      if(tResult[FLUFF]) {
	if(!hasError) {
	  hasError = true;
	  errorMSG = "[DETECTED: EXTRANEOUS WORDS";
	}
	else {
	  errorMSG += ", EXTRANEOUS WORDS";
	}
      }
      
      if(tResult[CONTRACTION]) {
        if(!hasError) {
          hasError = true;
          errorMSG = "[DETECTED: CONTRACTION";
        }
        else {
          errorMSG += ", CONTRACTION";
        }
      }
      if(tResult[PREPOSITION_ENDING]) {
        if(!hasError) {
          hasError = true;
          errorMSG = "[DETECTED: SENTENCE ENDS IN PREPOSITION";
        }
        else {
          errorMSG += ", SENTENCE ENDS IN PREPOSITION";
        }
      }
      errorMSG += "]";
      if(hasError) {
	//	writing[numSentences][0] = errorMSG + writing[numSentences][0];    //include this line to directly print the errors
      }
      numWords = 0;
      numSentences++;
      
      
      for(int i = 0; i < SIZE; i++) {
	tResult[i] = 0;
      }
      
      vector<string> * temp = new vector<string>();
      
      writing.push_back(*temp);
     
    }
    
  }
  
  /*parse repetitions*/
  
  for (std::pair<string, int> it : frequencyTable) {
    if(! (article.count(it.first) == 1) && !(preposition.count(it.first) == 1) && it.second > 1 && !(everythingElse.count(it.first) == 1)  ) {  
      errorCatalogue.push_back("{\"index\": [-1, -1], \"message\": \"You frequently use this word.\", \"word\" : \"" + it.first  + "\"}");
      
    }
  }
  
  
  std::cin.rdbuf(cinbuf);   //reset to standard input again
}

WritingChecker :: WritingChecker(string s, bool pref[SIZE]) {
  initialize();

  for(int i = 0; i < SIZE; i++) {
    features[i] = pref[i];
  }
  fileName = s;
}

void WritingChecker::addToHash(string word)
{
  frequencyTable[word] += 1;
}

bool WritingChecker::checkFirstPerson(int sentenceIndex, int wordIndex, string word)
{
  
  
  if (firstPerson.count(word) == 1) {
    if(wordIndex == 0) {
      return true;
    }
    if(wordIndex > 0 && article.count(writing[sentenceIndex][wordIndex - 1]) > 0) {
      return false;
    }
    return true;
  }
  
  return false;
}

bool WritingChecker::checkSecondPerson(int sentenceIndex, int wordIndex, string word) {
  if (secondPerson.count(word) == 1) {
    if(wordIndex == 0) {
      return true;
    }
    if(wordIndex > 0 && article.count(writing[sentenceIndex][wordIndex - 1]) > 0) {
      return false;
    }
    return true;
  }

  return false;
}

bool WritingChecker::checkFluff(string word) 
{
  if (fluff.count(word) == 1)
    {
      return true;
    }

  return false;
}

string WritingChecker::stripWord(string word)
{
  string output = "";
  for (int i = 0; i < word.length(); i++)
    {
      if (punctuation.count(word[i]) == 0)
	{
	  output += tolower(word[i]);
	}
    }

  return output;
}


bool WritingChecker::checkContraction(string word)
{
  for (int i = 0; i < word.length(); i++)
    {
      if (word[i] == '\'')
	{
	  //  cout<<word<<"CONTRACTY"<<endl;
	  if (word.length() - 1 == i)
	    {
	      return false;
	    }
	  else if (word[i + 1] != 's' || sContractions.count(word) == 1)
	    {
	      return true;
	    }
	}
    }

  return false;
}

string WritingChecker:: writingStringify() {
  string ret = "[";
  for(int i = 0; i < writing.size()-1; i++) {
    ret += "[\"" + writing[i][0] + "\"";
    for(int j = 0; j < writing[i].size(); j++) {
      if(j == 0) {
	
      }
      else {
	ret += ", \"" + writing[i][j] + "\"";
      }
    }
    if(i == writing.size()-2) {
      ret+="]";

    }
    else {
    ret += "],";
    }  
    
  }
  ret += "]";
  

  errorCatalogue.pop_back();

  ret = "{\"words\": " + ret + ", \"errors\": [";
  for(int i = 0; i < errorCatalogue.size(); i++) {
    if(i == errorCatalogue.size() - 1) {
      ret = ret   + errorCatalogue[i]  + "]}";
    }
    else {
      ret = ret + errorCatalogue[i] + ",";
    }
  }

  return ret;
}
/*                                                                                                                                                                                                        
{words: [[]], errors: [{index: [-1,-1], message: "dicks", word=""}]}                                                                                                                                    
  */
