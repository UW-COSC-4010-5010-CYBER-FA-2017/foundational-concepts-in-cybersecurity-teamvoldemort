#include <iostream>
#include "crowd.cpp"

using namespace std;

// Part 1 Section 2
// use hiddenData in person class, person class in crowd class
// to demonstrate modularity C4

int main(){
  Crowd* myCrowd = new Crowd();
  printf("First member of crowd is %s\n",myCrowd->people[0]._name.c_str());
  printf("size of crowd is %d\n",myCrowd->getSize());
}
