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
  void removeIngredients();
 


  Restriction::Restriction(string _name):name(_name){
    
  };

  Restriction::Restriction(string _name,ingredientLinkedList * _ingredients){
    ingredients = _ingredients;
    name = _name;
  };
