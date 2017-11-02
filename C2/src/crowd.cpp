#include "crowd.h"
#include <string>
#include <vector>

Crowd::Crowd(){
  vector<string> names = {"Jim","Mary","Joseph","John","Alice"};
  vector<string> jobs = {"Janitor","Librarian","Executive","Programmer"};
  vector<string> origins = {"Laramie","Cheyenne"};

  for(int i=0;i<names.size();i++){
    int age = 20;
    for(int j=0;j<jobs.size();j++){
      for(int x=0;x<origins.size();x++){
        people.push_back(Person(names[i],jobs[j],origins[x],age));
        age++;
      }
    }
  }
}

vector<Person>* Crowd::getTownies(string homeTown){
  vector<Person>* tmp = new vector<Person>();
  for(int i=0;i<people.size();i++){
    if(people[i]._origin==homeTown){
      tmp->push_back(people[i]);
    }
  }
  return tmp;
}

int Crowd::getSize(){
  return people.size();
}
