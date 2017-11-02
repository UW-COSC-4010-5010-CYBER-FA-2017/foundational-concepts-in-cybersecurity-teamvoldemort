## C2 - Resource Encapsulation
p1-2 = c6 - use hiddenData in person class, person class in crowd class
p1-2 demonstrates Resource Encapsulation by abstracting the hiddenData class into an object within the Person class, thus using the HiddenData class to allow the Person class access to only the necessary information retrieval functions.
*person.h*![encapsulate](../memes/resource-encapsulation.jpg)

```
class Person{
public:
  string _name, _job, _origin;
  int _age;
  HiddenData _extraInfo;//<<--!!
  Person();
  Person(string name,string job,string origin,int age);
};
```
