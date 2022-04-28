#include <iostream>
#include "restriction.h"

using namespace std;

class ingredientLinkedList{
private:
  string* data;
  ingredientNode* nextNode;
  int length;
public:
  Restriction returnNextRestrictionNode(); 
  void addRestriction();
  void removeRestriction();
  restrictionLinkedList();
};