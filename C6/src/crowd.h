#include "person.cpp"
#include <vector>

class Crowd{
public:
  vector<Person> people;
  Crowd();
  vector<Person>* getTownies(string homeTown);
  int getSize();
};
