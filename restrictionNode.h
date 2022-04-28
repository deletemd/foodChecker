#include <iostream>
#include "restriction.h"

using namespace std;

class restrictionNode{
private:
  Restriction * data;
  restrictionNode* nextNode;
public:
  void setData();
  Restriction * getData();
  void setNextNode(restrictionNode *newNode);
  restrictionNode* getNextNode();

  restrictionNode(string _name, ingredientLinkedList *_ingredients);
  
};