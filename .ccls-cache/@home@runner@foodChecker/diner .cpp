#include <iostream>
#include "diner.h"
using namespace std;

void Diner::setName (string _name){
  name = _name;
}
string Diner::getName (){
  return name;
}
void setAge ();
int getAge ();
void SetWeight ();
float getWeight ();
float calculateBMR ();
float calculateRecommendedCalories ();
// Restriction  getRestrictions ();
void setRestrictions ();
bool canEatMeal ();
string isMealHealthy();

Diner::Diner(string _name,int _age,float _weight, float _height ){
  name = _name;
  age = _age;
  wieght = _weight;
  height = -_height;
}
Diner(string _name,int _age,float _weight, float _height, string _ingredients[]);
