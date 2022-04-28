#include <iostream>
#include "ingredientLinkedList.h"

using namespace std;

class Meal{

private:
  ingredientLinkedList *ingredients;
  float calories;
  string name;

public:
  float getCalories ();
  void setCalories (float newCalories);
 void setName(string newName);
  string getName();

  ingredientLinkedList *getIngredients();
  void removeIngredients();

  Meal(string _name,float _calories);
  Meal(string _name,ingredientLinkedList *_ingredients,float _calories);

};