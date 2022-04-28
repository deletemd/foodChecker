#include <iostream>
#include "diner.h"
#include <string>
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

  if(meals->getLength()>0)
  {  meals->printInformation();
      cout<<endl<< isMealHealthy();

  }
  else{
    cout << endl<<"There are currently no meals for this diner yet"<<endl ;
  }
  
  cout << "The recommended amount of Calories is: " << calculateRecommendedCalories();

  
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
    string restrictionStr ="";
    restrictions->setData(restrictions->getHead());
    restrictions->getData()->getData()->getIngredients()->setData(restrictions->getData()->getData()->getIngredients()->getHead());
        
    while(restrictions->getData()!= nullptr)
      {
        while(restrictions->getData()->getData()->getIngredients()->getData() != nullptr){
         restrictionStr+=  restrictions->getData()->getData()->getIngredients()->getData()->getData();
          restrictions->getData()->getData()->getIngredients()->setData(restrictions->getData()->getData()->getIngredients()->getData()->getNextNode());
        
        }  
        
                     restrictions->setData(restrictions->getData()->getNextNode());
      }

      meals->setData(meals->getHead());
        meals->getHead()->getData()->getIngredients()->setData(meals->getHead()->getData()->getIngredients()->getHead());
    while(meals->getData()!= nullptr )
    {
     while(meals->getHead()->getData()->getIngredients()->getData() != nullptr){
       std::size_t found = restrictionStr.find(meals->getHead()->getData()->getIngredients()->getData()->getData());
     if(found != std::string::npos)
       {
         cout <<endl<< "Cannot eat " << meals->getData()->getData()->getIngredients()->getData()->getData()<<endl;
         canEat = false;
         break;

        
       }
        meals->getHead()->getData()->getIngredients()->setData(meals->getHead()->getData()->getIngredients()->getData()->getNextNode());
     } 
      
            meals->setData(meals->getData()->getNextNode());

    }
  }

  return canEat;
}
string Diner::isMealHealthy(){
  if (!canEatMeal()){
    return "This meal plan is unsafe";
  }
  else{
     float totalCalories =0;
      meals->setData(meals->getHead());
        
    while(meals->getData()!= nullptr )
    {
      totalCalories += meals->getData()->getData()->getCalories();
                 meals->setData(meals->getData()->getNextNode());
 
      }

    
 float neededCalories= calculateRecommendedCalories()- totalCalories;
    if (neededCalories> -250 && neededCalories < 250)
    {
          return  "This is a healthy meal plan! you have " + to_string(neededCalories) + " to spare."  ;
    }
    if (neededCalories< -500){
      return "It is recommended that you have one less snack/light meal you are currently over by " + to_string(-neededCalories);
    }

     if (neededCalories< -100){
      return "It is recommended that you have at least one less heavy meal you are currently over by " + to_string(-neededCalories);
    }

      if (neededCalories> 500){
      return "It is recommended that you have one more snack/light meal you are currently under by " + to_string(neededCalories);
    }

     if (neededCalories> -100){
      return "It is recommended that you have at least one more heavy meal you are currently under by " + to_string(neededCalories);
    }
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
