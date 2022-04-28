#include <iostream>
#include "mealNode.h"


using namespace std;

class mealLinkedList{
private:
  mealNode* head;
  mealNode* data;
  int length;
public:
  int getLength();
 mealNode* getHead();
  void setHead(mealNode* newNode);
 mealNode* getData();
 mealNode* getData(int id);
 mealNode* getData(int id, int counter);

void setData(mealNode * newNode);
  mealNode returnNextNode();
void addMeal(mealNode* node);
  void addMeal(string _name,ingredientLinkedList *ingredients,float _calories);
  void removeMeal();
  void printInformation();
  void search(string _query);
  mealLinkedList();
};