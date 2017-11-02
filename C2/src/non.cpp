#import "non.h"

Person non::newPerson(){
  return Person();
}

void non::setName(Person &p, string name){
  p._name = name;
}

void non::setJob(Person &p, string job){
  p._job = job;
}
