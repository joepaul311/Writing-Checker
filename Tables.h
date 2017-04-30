#ifndef TABLES_H
#define TABLES_H

#define PASSIVE 0
#define FIRST_PERSON 1
#define SECOND_PERSON 2
#define FLUFF 3
#define CONTRACTION 4
#define PREPOSITION_ENDING 5


#include <unordered_map>
#include <string>

using namespace std;


unordered_map<string, int> preposition;
unordered_map<string, int> toBe;
unordered_map<string, int> article;
unordered_map<string, int> sContractions;

unordered_map<string, int> firstPerson;
unordered_map<string, int> secondPerson;
unordered_map<string, int> fluff;
unordered_map<char, int> punctuation;

unordered_map<string, int> everythingElse;


void initialize() {
  for(int i = 33; i <= 47; i++) {
    if(i != 39 && i != 44) {
      punctuation[ ((char)i) ] = 1;
    }
  }
  for(int i = 58; i <= 64; i++) {
    punctuation[ ((char)i) ] = 1;
  }
  for(int i = 91; i <= 96; i++) {
    punctuation[ ((char)i) ] = 1;
  }
  for(int i = 123; i <=126; i++) {
    punctuation[ ((char)i) ] = 1;
  }
  
  article["a"] = 1;
  article["an"] = 1;
  article["the"] = 1;

  toBe["are"] = 1;
  toBe["was"] = 1;
  toBe["be"] = 1;
  toBe["is"] = 1;
  toBe["am"] = 1;
  toBe["were"] = 1;
  toBe["been"] = 1;
  toBe["being"] = 1;
  
  preposition["to"] = 1;
  preposition["with"] = 1;
  preposition["at"] = 1;
  preposition["from"] = 1;
  preposition["into"] = 1;
  preposition["during"] = 1;
  preposition["including"] = 1;
  preposition["until"] = 1;
  preposition["against"] = 1;
  preposition["among"] = 1;
  preposition["throughout"] = 1;
  preposition["despite"] = 1;
  preposition["towards"] = 1;
  preposition["upon"] = 1;
  preposition["concerning"] = 1;
  preposition["of"] = 1;
  preposition["to"] = 1;
  preposition["in"] = 1;
  preposition["for"] = 1;
  preposition["on"] = 1;
  preposition["by"] = 1;
  preposition["about"] = 1;
  preposition["like"] = 1;
  preposition["through"] = 1;
  preposition["over"] = 1;
  preposition["before"] = 1;
  preposition["between"] = 1;
  preposition["after"] = 1;
  preposition["since"] = 1;
  preposition["without"] = 1;
  preposition["under"] = 1;
  preposition["within"] = 1;
  preposition["along"] = 1;
  preposition["following"] = 1;
  preposition["across"] = 1;
  preposition["behind"] = 1;
  preposition["beyond"] = 1;
  preposition["plus"] = 1;
  preposition["except"] = 1;
  preposition["but"] = 1;
  preposition["up"] = 1;
  preposition["out"] = 1;
  preposition["around"] = 1;
  preposition["down"] = 1;
  preposition["off"] = 1;
  preposition["above"] = 1;
  preposition["near"] = 1;

  fluff["rather"] = 1;  
  fluff["little"] = 1;
  fluff["very"] = 1;
  fluff["quite"] = 1;
  fluff["literally"] = 1;
  fluff["legit"] = 1;
  fluff["legitimately"] = 1;


  firstPerson["i"] = 1;
  firstPerson["i'd"] = 1;
  firstPerson["i'dn't"] = 1;
  firstPerson["i'dn't've"] = 1;
  firstPerson["i'd've"] = 1;
  firstPerson["i'll"] = 1;
  firstPerson["i'm"] = 1;
  firstPerson["i've"] = 1;
  firstPerson["i'ven't"] = 1;

  firstPerson["me"] = 1;
  firstPerson["my"] = 1;
  firstPerson["mine"] = 1;

  firstPerson["we"] = 1;
  firstPerson["we'd"] = 1;
  firstPerson["we'dn't"] = 1;
  firstPerson["we'dn't've"] = 1;
  firstPerson["we'd've"] = 1;
  firstPerson["we'll"] = 1;
  firstPerson["we're"] = 1;
  firstPerson["we've"] = 1;
  firstPerson["we'ven't"] = 1;

  firstPerson["us"] = 1;
  firstPerson["our"] = 1;
  firstPerson["ours"] = 1;

  secondPerson["you"] = 1;
  secondPerson["you'd"] = 1;
  secondPerson["you'dn't"] = 1;
  secondPerson["you'dn't've"] = 1;
  secondPerson["you'd've"] = 1;
  secondPerson["you'll"] = 1;
  secondPerson["you'm"] = 1;
  secondPerson["you've"] = 1;
  secondPerson["you'ven't"] = 1;

  secondPerson["your"] = 1;
  secondPerson["yours"] = 1;

  secondPerson["we"] = 1;
  secondPerson["we'd"] = 1;
  secondPerson["we'dn't"] = 1;
  secondPerson["we'dn't've"] = 1;
  secondPerson["we'd've"] = 1;
  secondPerson["we'll"] = 1;
  secondPerson["we're"] = 1;
  secondPerson["we've"] = 1;
  secondPerson["we'ven't"] = 1;

  secondPerson["us"] = 1;
  secondPerson["our"] = 1;
  secondPerson["ours"] = 1;

  sContractions["it's"] = 1;
  sContractions["what's"] = 1;
  sContractions["he's"] = 1;
  sContractions["she's"] = 1;
  sContractions["how's"] = 1;
  sContractions["somebody's"] = 1;
  sContractions["someone's"] = 1;
  sContractions["something's"] = 1;
  sContractions["that's"] = 1;
  sContractions["there's"] = 1;
  sContractions["when's"] = 1;
  sContractions["where's"] = 1;
  sContractions["who's"] = 1;
  sContractions["why's"] = 1;

  everythingElse["because"] = 1;
  everythingElse["that"] = 1;
  everythingElse["may"] = 1;
  everythingElse["their"] = 1;
  everythingElse["and"] = 1;

}

#endif
