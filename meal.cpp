#include <iostream>
#include "meal.h"
using namespace std;


  void Meal::setName(string newName){
    name = newName;
  }
  string Meal::getName(){
    return name;
  }

float Meal::getCalories (){
  return calories;
}
  void Meal::setCalories (float _calories){
    calories = _calories;
  }

  ingredientLinkedList *Meal::getIngredients(){
    return ingredients;
  }
  void removeIngredients();
 


  Meal::Meal(string _name, float _calories):name(_name),calories(_calories){
    
  };

  Meal::Meal(string _name,ingredientLinkedList * _ingredients,float _calories){
    ingredients = _ingredients;
    name = _name;
    calories = _calories;
  };
