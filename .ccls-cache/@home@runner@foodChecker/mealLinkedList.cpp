#include <iostream>
#include "mealLinkedList.h"

using namespace std; 


mealNode* mealLinkedList::getHead(){
  return head;
}

void mealLinkedList::setHead(mealNode* mealNode){
  // head;
}

mealNode* mealLinkedList::getData(){
  return data;
}


mealNode* mealLinkedList::getData(int id){
  data= head;
  if(id == 1)
  {
    return head;
  }
  else{
   return getData(id, 2);
  }
}

mealNode* mealLinkedList::getData(int id, int counter){

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
void mealLinkedList::setData(mealNode *newNode){
  data = newNode; 
}

void mealLinkedList::addMeal(mealNode*node){
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
                  addMeal(node);
      break;
 }
   
 if(tolower(data->getData()->getName()[eachLetter])> tolower(node->getData()->getName()[eachLetter])){
            mealNode tempNode = *data;
            head = node;
            head->setNextNode(tempNode.getNextNode());
            data = head;
            addMeal(tempNode.getData()->getName(),tempNode.getData()->getIngredients(),tempNode.getData()->getCalories());
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
            addMeal(node);
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
            addMeal(node);
      break;
 }
          
          if(tolower(data->getNextNode()->getData()->getName()[eachLetter])> tolower(node->getData()->getName()[eachLetter])){
            mealNode tempNode = *data->getNextNode();
            
            node->setNextNode(tempNode.getNextNode());
            data->setNextNode(node);

            tempNode.setNextNode(nullptr);

            data = data->getNextNode();
            addMeal(tempNode.getData()->getName(),tempNode.getData()->getIngredients(),tempNode.getData()->getCalories());
            break;
          }
          else if(tolower(data->getNextNode()->getData()->getName()[eachLetter])< tolower(node->getData()->getName()[eachLetter])){
                   data = data->getNextNode();
            addMeal(node);
                    break;
        }

    }
        }
        }
      }
}



void mealLinkedList::addMeal(string _name,ingredientLinkedList *_ingredients,float _calories){
  mealNode* newNode = new mealNode(_name,_ingredients,_calories);


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
                  addMeal(_name,_ingredients,_calories);
      break;
 }
   
 if(tolower(data->getData()->getName()[eachLetter])> tolower(newNode->getData()->getName()[eachLetter])){
            mealNode tempNode = *data;
            head = newNode;
            head->setNextNode(tempNode.getNextNode());
            data = head;
            addMeal(tempNode.getData()->getName(),tempNode.getData()->getIngredients(),tempNode.getData()->getCalories());
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
            addMeal(_name,_ingredients,_calories);
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
            addMeal(_name,_ingredients,_calories);
      break;
 }
          
          if(tolower(data->getNextNode()->getData()->getName()[eachLetter])> tolower(newNode->getData()->getName()[eachLetter])){
            mealNode tempNode = *data->getNextNode();
            
            newNode->setNextNode(tempNode.getNextNode());
            data->setNextNode(newNode);

            tempNode.setNextNode(nullptr);

            data = data->getNextNode();
            addMeal(tempNode.getData()->getName(),tempNode.getData()->getIngredients(),tempNode.getData()->getCalories());
            break;
          }
          else if(tolower(data->getNextNode()->getData()->getName()[eachLetter])< tolower(newNode->getData()->getName()[eachLetter])){
                   data = data->getNextNode();
            addMeal(_name,_ingredients,_calories);
                    break;
        }

    }
        }
        }
      }
}
void mealLinkedList::printInformation(){
  data = head;
   cout<< "Meals: "<<endl;
  if(length ==0){
    cout<< "There are no meals in the system at the moment."<< endl ;
  }
  else{
  for(int eachmeal =1; eachmeal <= length; eachmeal ++){
    setData(getData(eachmeal));
    cout << eachmeal << ": " << getData()->getData()->getName()<<endl;
    }
  }
  cout<<endl;
}

  mealLinkedList::mealLinkedList(){
    length = 0;
    head = nullptr;
    data = nullptr; 
  }

int mealLinkedList::getLength(){
  return length;
}


void mealLinkedList::search(string _query){
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