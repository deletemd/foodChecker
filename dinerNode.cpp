#include "dinerNode.h"

using namespace std;

 void  dinerNode::setData(Diner *newNode){
   data = newNode;
 };

  Diner *dinerNode::getData(){
    return data;
  };

  void dinerNode::setNextNode(dinerNode* newNode){
    nextNode = newNode;
  }
  dinerNode* dinerNode::getNextNode(){
    return nextNode;
  }

 dinerNode::dinerNode(string _name,int _age,float _weight, float _height,char _sex):data(),nextNode(nullptr){
   data = new Diner (_name,_age,_weight,_height,_sex);
 }