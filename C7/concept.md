## C7 - Data Hiding
p1-1 demonstrates both the good and the bad ways of hiding data from a user.
This program successfully prevents a user record's Social Security and Phone Number fields from being exposed by setting them to private and only allowing access through custom modifiers. However the program also shows an unsafe example of hiding by accidentally leaking the phone number when the call_number() function is called, thus subverting the variables private status.
![yall got any more data](../memes/datahiding.jpg)

*hidden.cpp*
```
...
int HiddenData::getSSnum(){
  cout << ">nope you can't look at the SS# directly" << endl;
  return 0;
}
...
//preventing the user from *seeing* the full phone number
//number will still be viewable in memory
int HiddenData::getPhoneNum(){
  cout << ">this is a private field so you must use our modifier\n";
  cout << ">and we only give you the last 4 numbers\n";
  string tmpNum = to_string(phoneNum);

  tmpNum = tmpNum.substr((tmpNum.length()-4),tmpNum.length());
  return stoi(tmpNum);
}

//OOPS! we accidentally revealed the phone number!
void HiddenData::callNumber(){
  string num = to_string(phoneNum);
  cout << ">Calling " << num.at(0) << num.at(1) << num.at(2) << "-";
  cout << num.at(3) << num.at(4) << num.at(5) << num.at(6) << endl;
  for(int i=0;i<5;i++){cout<<".";sleep(2);}//
  cout << " *disconnected*" << endl;
}
```

### Good Example
*hidden.h*
```
...
class HiddenData{
private:
  ulong SSnum;
  ulong phoneNum;
...
```
*hidden.cpp*
```
...
int HiddenData::getSSnum(){
  cout << ">nope you can't look at the SS# directly" << endl;
  return 0;
}
...
int HiddenData::getPhoneNum(){
  cout << ">this is a private field so you must use our modifier\n";
  cout << ">and we only give you the last 4 numbers\n";
  string tmpNum = to_string(phoneNum);

  tmpNum = tmpNum.substr((tmpNum.length()-4),tmpNum.length());
  return stoi(tmpNum);
}
```
### Bad Example
*hidden.cpp*
```
//OOPS! we accidentally revealed the phone number!
void HiddenData::callNumber(){
  string num = to_string(phoneNum);
  cout << ">Calling " << num.at(0) << num.at(1) << num.at(2) << "-";
  cout << num.at(3) << num.at(4) << num.at(5) << num.at(6) << endl;
  for(int i=0;i<5;i++){cout<<".";sleep(2);}//
  cout << " *disconnected*" << endl;
}
```
