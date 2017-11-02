## C5 - Layering
p1-4 demonstrates layering through the encapsulation of the Crowd class in a authentication class to enable a natural selection function on the Crowd. The bad example merely removes the password check to show a bad example of adding a secure layer.
![shrek security layers](../memes/layers-shrek.jpg)

*secureCrowd.h*
```
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
```
