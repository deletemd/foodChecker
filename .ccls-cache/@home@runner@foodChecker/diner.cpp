#include <iostream>
#include "diner.h"
using namespace std;

void Diner::setName (string _name){
  name = _name;
}
string Diner::getName (){
  return name;
}
void Diner::setAge (int newAge){
  age = newAge;
}
int Diner::getAge (){
  return age;
}
void Diner::setWeight (float newWeight){
  weight= newWeight;
}
float Diner::getWeight (){
  return weight;
}

void Diner::setHeight (float newHeight){
  height= newHeight;
};
float Diner::getHeight (){
  return height;
}


void Diner::setSex (char _sex){
  sex = _sex;
}
char Diner::getSex (){
  return sex;
}

void Diner::printInformation(){
  cout<< "Name: " << name<<endl;
  cout<< "Age: " << age<<endl;
  cout<< "Weight: " << weight<<"kg"<<endl;
  cout<< "Height: " << height<<"cm"<<endl;
  restrictions->printInformation();
  cout <<endl;
  meals->printInformation();
  
  cout << "The recommended amount of Calories is: " << calculateRecommendedCalories();

  cout<<endl<< isMealHealthy();
}


float Diner::calculateBMR(){
  if(sex =='m'){
  return  88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
  }
  else{
   return  447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age );
  }
}
float Diner::calculateRecommendedCalories (){
  return(1.2* calculateBMR());
}
restrictionLinkedList* Diner::getRestrictions (){
  return restrictions;
};

void setRestrictions ();

mealLinkedList* Diner::getMeals (){
  return meals;
};

bool Diner::canEatMeal (){
  bool canEat = true;
  if(restrictions->getLength()>0 && meals->getLength()>0)
  {
    restrictions->setData(restrictions->getHead());
    restrictions->getData()->getData()->getIngredients()->setHead(restrictions->getData()->getData()->getIngredients()->getHead());
        cout << restrictions->getData()->getData()->getName();

    while(restrictions->getData()!= nullptr)
      {
            meals->setData(meals->getHead());
    while(meals->getData()!= nullptr)
    {
      cout << restrictions->getData()->getData()->getIngredients()->getData()->getData();
      meals->getData()->getData()->getIngredients()->search(restrictions->getData()->getData()->getIngredients()->getData()->getData());
      if(meals->getData()->getData()->getIngredients()->getData() != nullptr)
      {
        cout <<endl<< "Cannot eat " << meals->getData()->getData()->getIngredients()->getData()->getData()<<endl;
        canEat = false;
        break;
      }
            meals->setData(meals->getData()->getNextNode());

    }
        
                    restrictions->setData(restrictions->getData()->getNextNode());
 restrictions->getData()->getData()->getIngredients()->setHead(restrictions->getData()->getData()->getIngredients()->getHead());
                cout << restrictions->getData()->getData()->getName();

      }
  }

  return canEat;
}
string Diner::isMealHealthy(){
  if (!canEatMeal()){
    return "This meal plan is unsafe";
  }
}

Diner::Diner(string _name,int _age,float _weight, float _height, char _sex ){
  name = _name;
  age = _age;
  weight = _weight;
  height = _height;
  restrictions = new restrictionLinkedList();
    meals = new mealLinkedList();
  sex= _sex;
}


Diner::Diner(string _name,int _age,float _weight, float _height, string _ingredients[],char _sex){
   name = _name;
  age = _age;
  weight = _weight;
  height = _height;
restrictions = new restrictionLinkedList();
  meals = new mealLinkedList();
  sex = _sex;
}
