#include <iostream>
#include "ingredientLinkedList.h"
using namespace std;
class Restriction{

private:
  string name;
  ingredientLinkedList *ingredients;


public: 
  void setName(string newName);
  string getName();

  ingredientLinkedList *getIngredients();
  void removeIngredients();
  Restriction(string _name);
  Restriction(string _name,ingredientLinkedList* _ingredients);
};