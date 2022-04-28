#include <iostream>

using namespace std;
class Restriction{

private:
  string name;
  int numberOfIngredients;
  string ingredients[0];


public: 
  void setName();
  string getName();
  void setIngredients();
  string getIngredients();
  void addIngredients ();
  void setIngrdients ();
  string returnIngredients();
  void removeIngredients();
  Restriction(string _name);
  Restriction(string _name,string _ingredients[]);
}