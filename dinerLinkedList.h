#include <iostream>
#include "dinerNode.h"


using namespace std;

class dinerLinkedList{
private:
  dinerNode* head;
  dinerNode* data;
  int length;
public:
  int getLength();
  dinerNode* getHead();
  void setHead(dinerNode* newNode);
 dinerNode* getData();
 dinerNode* getData(int id);
dinerNode* getData(int id,int counter);
  void setData(dinerNode* newNode);
  Diner returnNextDinerNode(); 
  void addDiner(string _name,int _age,float _weight, float _height,char _sex);
  void removeDiner(dinerNode *node);
  dinerLinkedList();
  void search(string query);
};