#include <iostream>
#include "dinerLinkedList.h"

using namespace std; 

  Diner dinerLinkedList::returnNextDinerNode(){
    // return nextNode;
  }

dinerNode* dinerLinkedList::getHead(){
  return head;
}

void dinerLinkedList::setHead(dinerNode* dinerNode){
   head = dinerNode;
}

dinerNode* dinerLinkedList::getData(){
  return data;
}

dinerNode* dinerLinkedList::getData(int id){
  data= head;
  if(id == 1)
  {
    return head;
  }
  else{
   return getData(id, 2);
  }
}

dinerNode* dinerLinkedList::getData(int id, int counter){

  setData(getData()->getNextNode());
      
  if(counter == id)
  { 
          
    return data;
  }
  else{
    counter +=1;
    return  getData(id,counter);
  }
}

void dinerLinkedList::setData(dinerNode* newNode){
  data = newNode; 
}
int dinerLinkedList::getLength(){
  return length;
}
void dinerLinkedList::addDiner(string _name,int _age,float _weight, float _height,char _sex){
  dinerNode* newDinerNode =new dinerNode(_name,_age, _weight, _height,_sex);
  if(head == nullptr )
  {
    head = newDinerNode;
      length ++;
  }
  else if(data == nullptr){
    
    data = head;
         int orderByLenght=0;
        if(data->getData()->getName().length()< newDinerNode->getData()->getName().length())
        {
         orderByLenght = data->getData()->getName().length();
        }
        else{
                   orderByLenght = newDinerNode->getData()->getName().length();
        }
    
  for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
    
   if(eachLetter == orderByLenght){
     cout <<eachLetter;
                  addDiner(_name,_age,_weight,_height,_sex);
      break;
 }
   
 if(tolower(data->getData()->getName()[eachLetter])> tolower(newDinerNode->getData()->getName()[eachLetter])){
            dinerNode tempNode = *data;
            head = newDinerNode;
            head->setNextNode(tempNode.getNextNode());
            data = head;
            cout<<"move "<<tempNode.getData()->getName() <<endl;  
            addDiner(tempNode.getData()->getName(),tempNode.getData()->getAge(),tempNode.getData()->getWeight(),tempNode.getData()->getHeight(),tempNode.getData()->getSex());
            break;
          }
          else if(tolower(data->getData()->getName()[eachLetter])< tolower(newDinerNode->getData()->getName()[eachLetter])){
              if(data->getNextNode() ==  nullptr)
    {
          data->setNextNode(newDinerNode);
          data = nullptr;
          length ++;
    }
   else{
    addDiner(_name,_age,_weight,_height,_sex);
   }
            
    break;
    }
   }
    }
    else{
    while(data != nullptr)
      {

            if(data->getNextNode() ==  nullptr)
    {
          data->setNextNode(newDinerNode);
          data = nullptr;
          length ++;
      break;
    }
        else{
         int orderByLenght=0;
        if(data->getNextNode()->getData()->getName().length()< newDinerNode->getData()->getName().length())
        {
         orderByLenght = data->getNextNode()->getData()->getName().length();
        }
        else{
                   orderByLenght = newDinerNode->getData()->getName().length();
        }

        for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
          
 if(eachLetter == orderByLenght){
   data = data->getNextNode();
                  addDiner(_name,_age,_weight,_height,_sex);
      break;
 }
          
          if(tolower(data->getNextNode()->getData()->getName()[eachLetter])> tolower(newDinerNode->getData()->getName()[eachLetter])){
            dinerNode tempNode = *data->getNextNode();
            
            newDinerNode->setNextNode(tempNode.getNextNode());
            data->setNextNode(newDinerNode);

            tempNode.setNextNode(nullptr);

            data = data->getNextNode();
            addDiner(tempNode.getData()->getName(),tempNode.getData()->getAge(),tempNode.getData()->getWeight(),tempNode.getData()->getHeight(),tempNode.getData()->getSex());
            break;
          }
          else if(tolower(data->getNextNode()->getData()->getName()[eachLetter])< tolower(newDinerNode->getData()->getName()[eachLetter])){
                   data = data->getNextNode();
                  addDiner(_name,_age,_weight,_height,_sex);
                    break;
        }

    }
        }
        }
      }
}

void dinerLinkedList::removeDiner(dinerNode *node){
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

void dinerLinkedList::search(string _query){
    data = head;

  while(data != nullptr)
    {

      if(data->getData()->getName()== _query)
      {
        break;
      }
      data = data->getNextNode();
    }
}