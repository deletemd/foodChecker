#include <iostream>
#include "ingredientLinkedList.h"

using namespace std; 


ingredientNode* ingredientLinkedList::getHead(){
  return head;
}

void ingredientLinkedList::setHead(ingredientNode* ingredientNode){
   head = ingredientNode;
}

ingredientNode* ingredientLinkedList::getData(){
  return data;
}


ingredientNode* ingredientLinkedList::getData(int id){
  data= head;
  if(id == 1)
  {
    return head;
  }
  else{
   return getData(id, 2);
  }
}

ingredientNode* ingredientLinkedList::getData(int id, int counter){

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

void ingredientLinkedList::setData(ingredientNode *newNode){
  data = newNode; 
}

int ingredientLinkedList::getLength(){
  return length;
}
void ingredientLinkedList::addIngredient(string _ingredient){
  ingredientNode * newNode = new ingredientNode(_ingredient);

  
  if(head == nullptr )
  {
    head = newNode;
      length ++;
  }
  else if(data == nullptr){
    
    data = head;
         int orderByLenght=0;
        if(data->getData().length()< newNode->getData().length())
        {
         orderByLenght = data->getData().length();
        }
        else{
                   orderByLenght = newNode->getData().length();
        }
    
  for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
    
   if(eachLetter == orderByLenght){
                  addIngredient(_ingredient);
      break;
 }
   
 if(tolower(data->getData()[eachLetter])> tolower(newNode->getData()[eachLetter])){
            ingredientNode tempNode = *data;
            head = newNode;
            head->setNextNode(tempNode.getNextNode());
            data = head;
            addIngredient(tempNode.getData());
            break;
          }
          else if(tolower(data->getData()[eachLetter])< tolower(newNode->getData()[eachLetter])){
              if(data->getNextNode() ==  nullptr)
    {
          data->setNextNode(newNode);
          data = nullptr;
          length ++;
    }
   else{
            addIngredient(_ingredient);
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
        if(data->getNextNode()->getData().length()< newNode->getData().length())
        {
         orderByLenght = data->getNextNode()->getData().length();
        }
        else{
                   orderByLenght = newNode->getData().length();
        }

        for(int eachLetter =0; eachLetter <= orderByLenght; eachLetter ++){
          
 if(eachLetter == orderByLenght){
   data = data->getNextNode();
            addIngredient(_ingredient);
      break;
 }
          
          if(tolower(data->getNextNode()->getData()[eachLetter])> tolower(newNode->getData()[eachLetter])){
            ingredientNode tempNode = *data->getNextNode();
            
            newNode->setNextNode(tempNode.getNextNode());
            data->setNextNode(newNode);

            tempNode.setNextNode(nullptr);

            data = data->getNextNode();
            addIngredient(tempNode.getData());            break;
          }
          else if(tolower(data->getNextNode()->getData()[eachLetter])< tolower(newNode->getData()[eachLetter])){
                   data = data->getNextNode();
            addIngredient(_ingredient);
                    break;
        }

    }
        }
        }
      }
}

void ingredientLinkedList::printInformartion(){
   setData(getHead());
   cout<< "Ingredients: "<<endl;
  if(getLength() ==0){
    cout<< "There are no restrictions in the system at the moment."<< endl ;
  }
  else{
  for(int eachIngredient =1; eachIngredient <= getLength(); eachIngredient ++){
    setData(getData(eachIngredient));
    cout << eachIngredient << ": " << getData()->getData()<<endl;
    }
}
}

void ingredientLinkedList::removeIngredient(ingredientNode* node){
    length --;
  if(node !=nullptr)
  {
      ingredientNode* target = node->getNextNode();
  node->setNextNode(target->getNextNode());
  }
  cout << length;
    cout << length;

}

  ingredientLinkedList::ingredientLinkedList(){
    length = 0;
    data = nullptr;
    head = nullptr;
  }

void ingredientLinkedList::search(string _query){
    data = head;

  while(data != nullptr)
    {

      if(data->getData()== _query)
      {
        break;
      }
      data = data->getNextNode();
    }
}