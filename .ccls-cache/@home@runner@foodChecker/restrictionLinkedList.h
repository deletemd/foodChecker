#include <iostream>
#include "restrictionNode.h"


using namespace std;

class restrictionLinkedList{
private:
  restrictionNode* head;
  restrictionNode* data;
  int length;
public:
  int getLength();
 restrictionNode* getHead();
  void setHead(restrictionNode* newNode);
 restrictionNode* getData();
 restrictionNode* getData(int id);
 restrictionNode* getData(int id, int counter);

void setData(restrictionNode * newNode);
  restrictionNode returnNextNode();
void addRestriction(restrictionNode* node);
  void addRestriction(string _name,ingredientLinkedList *ingredients);
  void removeRestriction(restrictionNode*node);
  void printInformation();
  void search(string _query);
  restrictionLinkedList();
};