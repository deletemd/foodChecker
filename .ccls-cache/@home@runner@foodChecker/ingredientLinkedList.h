#include <iostream>
#include "ingredientNode.h"
#pragma once

using namespace std;

class ingredientLinkedList{
private:
  ingredientNode* head;
  ingredientNode* data;
  int length;
public:
  int getLength();
 ingredientNode* getHead();
  void setHead(ingredientNode* newNode);
 ingredientNode* getData();
 ingredientNode* getData(int id);
 ingredientNode* getData(int id, int counter);
  void setData(ingredientNode* newNode);

void printInformartion();
  void search(string _query);

  void addIngredient(string _ingredient);
  void removeIngredient(ingredientNode*node);
  ingredientLinkedList();

};

