#include <iostream>
#include "diner.h"


using namespace std;

class dinerNode{
private:
  Diner* data;
  dinerNode* nextNode;
public:
  void setData(Diner * data);
  Diner* getData();
  void setNextNode(dinerNode* newNode);
  dinerNode* getNextNode();

  dinerNode(string _name,int _age,float _weight, float _height,char _sex);
  
};