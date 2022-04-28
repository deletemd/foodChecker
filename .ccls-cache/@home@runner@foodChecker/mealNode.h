#include <iostream>
#include "meal.h"


using namespace std;

class mealNode{
private:
  Meal * data;
  mealNode* nextNode;
public:
  void setData();
  Meal * getData();
  void setNextNode(mealNode *newNode);
  mealNode* getNextNode();

  mealNode(string _name, ingredientLinkedList *_ingredients,float _calories);
  
};