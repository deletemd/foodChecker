#include "ingredientNode.h"

using namespace std;

 void ingredientNode::setData(string  newIngredient){
  data =  newIngredient;
 }

  string  ingredientNode::getData(){
    return data;
  }

  void ingredientNode::setNextNode(ingredientNode* newNode){
    nextNode = newNode;
  }
  ingredientNode* ingredientNode::getNextNode(){
    return nextNode;
  }

 ingredientNode::ingredientNode(string _ingredient){
   data = _ingredient;
   }


   