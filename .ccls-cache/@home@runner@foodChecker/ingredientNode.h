#include <iostream>

using namespace std;

class ingredientNode{
private:
  string data;
  ingredientNode* nextNode;
public:
  void setData(string newIngredient);
  string getData();
  void setNextNode(ingredientNode* newNode);
  ingredientNode* getNextNode();

  ingredientNode(string _ingredient);
  
};