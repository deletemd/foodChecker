#include "restrictionNode.h"

using namespace std;

 void setData();

  Restriction * restrictionNode::getData(){
    return data;
  }
 void setData();
  Restriction* getData();
  void restrictionNode::setNextNode(restrictionNode *newNode){
    nextNode = newNode;
  }

restrictionNode* restrictionNode::getNextNode(){
    return nextNode;
  }


 restrictionNode::restrictionNode(string _name, ingredientLinkedList* _ingredients){
   data =new Restriction(_name,_ingredients);

   
 }