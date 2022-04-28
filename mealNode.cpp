#include "mealNode.h"

using namespace std;

 void setData();

  Meal * mealNode::getData(){
    return data;
  }
 void setData();
  Meal* getData();
  void mealNode::setNextNode(mealNode *newNode){
    nextNode = newNode;
  }

mealNode* mealNode::getNextNode(){
    return nextNode;
  }


 mealNode::mealNode(string _name, ingredientLinkedList* _ingredients, float _calories){
   data =new Meal(_name,_ingredients,_calories);

   
 }