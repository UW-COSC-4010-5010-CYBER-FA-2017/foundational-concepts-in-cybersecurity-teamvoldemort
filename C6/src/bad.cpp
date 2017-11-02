#include "non.cpp"

int main(){
  non n = non();
  Person p = n.newPerson();
  n.setName(p,"Jim");
  printf("set name as %s\n",p._name.c_str());
  n.setJob(p,"Janitor");
  printf("set job as %s\n",p._job.c_str());
  return 0;
}
