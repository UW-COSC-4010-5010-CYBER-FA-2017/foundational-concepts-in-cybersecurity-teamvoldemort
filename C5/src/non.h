#include "crowd.cpp"
#include <vector>

class inSecureCrowd{
public:
  Crowd myCrowd;
  inSecureCrowd();//constructor
  void login(string password);
  bool isLoggedIn();
  void engageNaturalSelection();

private:
  bool loggedIn;
};
