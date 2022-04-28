#include <iostream>
#include "restrictionLinkedList.h"
#include "mealLinkedList.h"
using namespace std;

class Diner{
private:
  string name;
  int age;
char sex;
  float weight;
  float height;
  float BMR;
  float recommendedCalories;
  restrictionLinkedList * restrictions;
mealLinkedList *meals;
public:
  void setName (string _name);
  string getName ();
  void setAge (int newAge);
  int getAge ();
  void setWeight (float newWeight);
  float getWeight ();
  void setHeight (float newHeight);
  float getHeight ();
 void setSex (char _sex);
  char getSex ();
  float calculateBMR ();
  float calculateRecommendedCalories ();
  restrictionLinkedList*  getRestrictions ();
mealLinkedList * getMeals();
  bool canEatMeal ();
  string isMealHealthy();
void printInformation();
  
  Diner(string _name,int _age,float _weight, float _height,char sex );
  Diner(string _name,int _age,float _weight, float _height, string _ingredients[],char _sex);

};