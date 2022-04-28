#include <iostream>
#include "restriction.h"

using namespace std;

class dinerLinkedList{
private:
  Diner data;
  Diner nextNode;
  int length;
public:
  Diner returnNextDinerNode(); 
  void addDiner();
  void removeDiner();
  dinerLinkedList(Diner _diner);
}