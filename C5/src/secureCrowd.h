#include "crowd.cpp"
#include <vector>

class SecureCrowd{
public:
  Crowd myCrowd;
  SecureCrowd();//constructor
  void login(string password);
  bool isLoggedIn();
  void engageNaturalSelection();

private:
  bool loggedIn;
};
