## C6 - Abstraction
p1-2 demonstrates abstraction by using multiple classes to eliminate unnecessary details during certain stages of development. When designing each class it is possible to focus on the functionality of that particular class, while simply believing the fact that we know the classes we are building on top of will work correctly. This is the main principle behind reusing code and allows us to be certain our underlying libraries have been tested to work properly. The good example shows an example of building a Crowd class on top of a Person class which uses the HiddenData class.
![meta jerry](../memes/abstraction.jpg)

*crowd.h*
```
class Crowd{
public:
  vector<Person> people;
  Crowd();
  vector<Person>* getTownies(string homeTown);
  int getSize();
};
```

The non example merely transforms the Person class and doesn't add any significant functionality.

*non.h*
```
class non{
public:
  Person newPerson();
  void setName(Person &p, string name);
  void setJob(Person &p, string job);
};
```
