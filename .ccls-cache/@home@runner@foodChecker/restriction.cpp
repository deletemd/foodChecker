#include <iostream>
#include "restriction.h"
using namespace std;


  void Restriction::setName(string newName){
    name = newName;
  }
  string Restriction::getName(){
    return name;
  }
 
  ingredientLinkedList *Restriction::getIngredients(){
    return ingredients;
  }
void restric::removeDiner(dinerNode *node){
  if(node !=nullptr)
  {
      dinerNode* target = node->getNextNode();
  node->setNextNode(target->getNextNode());
  }
  length --;

}
  dinerLinkedList::dinerLinkedList(){
    length = 0;
    data = nullptr;
    head = nullptr;
  } 


  Restriction::Restriction(string _name):name(_name){
    
  };

  Restriction::Restriction(string _name,ingredientLinkedList * _ingredients){
    ingredients = _ingredients;
    name = _name;
  };
