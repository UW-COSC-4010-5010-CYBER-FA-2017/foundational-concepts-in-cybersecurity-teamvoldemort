#include "secureCrowd.h"

SecureCrowd::SecureCrowd(){
  myCrowd = Crowd();
}

void SecureCrowd::login(string pass){
  if(pass=="admin"){
    loggedIn=true;
  }
}

bool SecureCrowd::isLoggedIn(){
  return loggedIn;
}

void SecureCrowd::engageNaturalSelection(){
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
