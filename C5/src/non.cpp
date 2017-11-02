#include "non.h"

inSecureCrowd::inSecureCrowd(){
  myCrowd = Crowd();
}

void inSecureCrowd::login(string pass){
    loggedIn=true;
}

bool inSecureCrowd::isLoggedIn(){
  return loggedIn;
}

void inSecureCrowd::engageNaturalSelection(){
  if(loggedIn){
    for (auto it = myCrowd.people.begin(); it != myCrowd.people.end(); ) {
        if (it->_age > 28) {
            it = myCrowd.people.erase(it);
        } else {
            ++it;
        }
    }
  }
}
