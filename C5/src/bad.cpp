#include <iostream>
#include "non.cpp"

using namespace std;

// part 1 section 4
// demonstrate layering by wrapping Crowd in a security class

int main(){
  inSecureCrowd* mySecureCrowd = new inSecureCrowd();
  printf("size of crowd before pruning is %d\n",mySecureCrowd->myCrowd.getSize());
  while(!mySecureCrowd->isLoggedIn()){
    printf("enter password to login: \n");
    string inp;
    cin >> inp;
    mySecureCrowd->login(inp);
  }
  mySecureCrowd->engageNaturalSelection();
  printf("size of crowd after pruning is %d\n",mySecureCrowd->myCrowd.getSize());
}
