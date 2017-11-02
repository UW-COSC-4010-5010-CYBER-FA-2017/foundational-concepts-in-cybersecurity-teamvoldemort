#include <string>
#include "hidden.cpp"//gonna hide the important info

class Person{
public:
  string _name, _job, _origin;
  int _age;
  HiddenData _extraInfo;
  Person();
  Person(string name,string job,string origin,int age);
};
