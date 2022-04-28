#include <iostream>
#include "restrictionLinkedList.h"

using namespace std; 


restrictionNode* restrictionLinkedList::getHead(){
  return head;
}

void restrictionLinkedList::setHead(restrictionNode* restrictionNode){
   head = restrictionNode;
}

restrictionNode* restrictionLinkedList::getData(){
  return data;
}


restrictionNode* restrictionLinkedList::getData(int id){
  data= head;
  if(id == 1)
  {
    return head;
  }
  else{
   return getData(id, 2);
  }
}

restrictionNode* restrictionLinkedList::getData(int id, int counter){

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
void restrictionLinkedList::setData(restrictionNode *newNode){
  data = newNode; 
}

void restrictionLinkedList::addRestriction(restrictionNode*node){
  if(head == nullptr )
  {

    head = node;
      length ++;
    printInformation();
  }
  else if(data == nullptr){
    data = head;
         int orderByLenght=0;
        if(data->getData()->getName().length()< node->getData()->getName().length())
        {
         orderByLenght = data->getData()->getName().length();
        }
        else{
                   orderByLenght = node->getData()->getName().length();
        }
    
  for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
    
   if(eachLetter == orderByLenght){
                  addRestriction(node);
      break;
 }
   
 if(tolower(data->getData()->getName()[eachLetter])> tolower(node->getData()->getName()[eachLetter])){
            restrictionNode tempNode = *data;
            head = node;
            head->setNextNode(tempNode.getNextNode());
            data = head;
            addRestriction(tempNode.getData()->getName(),tempNode.getData()->getIngredients());
            break;
          }
          else if(tolower(data->getData()->getName()[eachLetter])< tolower(node->getData()->getName()[eachLetter])){
              if(data->getNextNode() ==  nullptr)
    {
          data->setNextNode(node);
          data = nullptr;
          length ++;
    }
   else{
            addRestriction(node);
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
          data->setNextNode(node);
          data = nullptr;
          length ++;
      break;
    }
        else{
         int orderByLenght=0;
        if(data->getNextNode()->getData()->getName().length()< node->getData()->getName().length())
        {
         orderByLenght = data->getNextNode()->getData()->getName().length();
        }
        else{
                   orderByLenght = node->getData()->getName().length();
        }

        for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
          
 if(eachLetter == orderByLenght){
   data = data->getNextNode();
            addRestriction(node);
      break;
 }
          
          if(tolower(data->getNextNode()->getData()->getName()[eachLetter])> tolower(node->getData()->getName()[eachLetter])){
            restrictionNode tempNode = *data->getNextNode();
            
            node->setNextNode(tempNode.getNextNode());
            data->setNextNode(node);

            tempNode.setNextNode(nullptr);

            data = data->getNextNode();
            addRestriction(tempNode.getData()->getName(),tempNode.getData()->getIngredients());
            break;
          }
          else if(tolower(data->getNextNode()->getData()->getName()[eachLetter])< tolower(node->getData()->getName()[eachLetter])){
                   data = data->getNextNode();
            addRestriction(node);
                    break;
        }

    }
        }
        }
      }
}



void restrictionLinkedList::addRestriction(string _name,ingredientLinkedList *_ingredients){
  restrictionNode* newNode = new restrictionNode(_name,_ingredients);


  if(head == nullptr )
  {
    head = newNode;
      length ++;
  }
  else if(data == nullptr){
    
    data = head;
         int orderByLenght=0;
        if(data->getData()->getName().length()< newNode->getData()->getName().length())
        {
         orderByLenght = data->getData()->getName().length();
        }
        else{
                   orderByLenght = newNode->getData()->getName().length();
        }
    
  for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
    
   if(eachLetter == orderByLenght){
                  addRestriction(_name,_ingredients);
      break;
 }
   
 if(tolower(data->getData()->getName()[eachLetter])> tolower(newNode->getData()->getName()[eachLetter])){
            restrictionNode tempNode = *data;
            head = newNode;
            head->setNextNode(tempNode.getNextNode());
            data = head;
            addRestriction(tempNode.getData()->getName(),tempNode.getData()->getIngredients());
            break;
          }
          else if(tolower(data->getData()->getName()[eachLetter])< tolower(newNode->getData()->getName()[eachLetter])){
              if(data->getNextNode() ==  nullptr)
    {
          data->setNextNode(newNode);
          data = nullptr;
          length ++;
    }
   else{
            addRestriction(_name,_ingredients);
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
          data->setNextNode(newNode);
          data = nullptr;
          length ++;
      break;
    }
        else{
         int orderByLenght=0;
        if(data->getNextNode()->getData()->getName().length()< newNode->getData()->getName().length())
        {
         orderByLenght = data->getNextNode()->getData()->getName().length();
        }
        else{
                   orderByLenght = newNode->getData()->getName().length();
        }

        for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
          
 if(eachLetter == orderByLenght){
   data = data->getNextNode();
            addRestriction(_name,_ingredients);
      break;
 }
          
          if(tolower(data->getNextNode()->getData()->getName()[eachLetter])> tolower(newNode->getData()->getName()[eachLetter])){
            restrictionNode tempNode = *data->getNextNode();
            
            newNode->setNextNode(tempNode.getNextNode());
            data->setNextNode(newNode);

            tempNode.setNextNode(nullptr);

            data = data->getNextNode();
            addRestriction(tempNode.getData()->getName(),tempNode.getData()->getIngredients());
            break;
          }
          else if(tolower(data->getNextNode()->getData()->getName()[eachLetter])< tolower(newNode->getData()->getName()[eachLetter])){
                   data = data->getNextNode();
            addRestriction(_name,_ingredients);
                    break;
        }

    }
        }
        }
      }
}
void restrictionLinkedList::printInformation(){
  data = head;
   cout<< "Restrictions: "<<endl;
  if(length ==0){
    cout<< "There are no restrictions in the system at the moment."<< endl ;
  }
  else{
  for(int eachRestriction =1; eachRestriction <= length; eachRestriction ++){
    setData(getData(eachRestriction));
    cout << eachRestriction << ": " << getData()->getData()->getName()<<endl;
    }
  }
  cout<<endl;
}

  restrictionLinkedList::restrictionLinkedList(){
    length = 0;
    head = nullptr;
    data = nullptr; 
  }

int restrictionLinkedList::getLength(){
  return length;
}


void restrictionLinkedList::search(string _query){
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

void restrictionLinkedList::removeRestriction(restrictionNode *node){
  if(node !=nullptr)
  {
      restrictionNode* target = node->getNextNode();
  node->setNextNode(target->getNextNode());
  }
  length --;

}
  