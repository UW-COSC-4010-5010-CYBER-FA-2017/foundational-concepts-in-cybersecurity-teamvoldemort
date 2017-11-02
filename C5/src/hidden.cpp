#include <iostream>
#include <unistd.h>
#include <thread>
#include <string>
#include "hidden.h"
using namespace std;

//return true if SS is set
bool HiddenData::hasSS(){
  return (SSnum == 0)? true: false;
}

void HiddenData::setSSnum(int ss){
  SSnum = ss;
}

int HiddenData::getSSnum(){
  cout << ">nope you can't look at the SS# directly" << endl;
  return 0;
}

bool HiddenData::hasPhoneNum(){
  return (phoneNum == 0)? true: false;
}

void HiddenData::setPhoneNum(int num){
  phoneNum = num;
}

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

void HiddenData::printAddr(){
  cout << ">we will share address info because we feel like it\n";
  cout << fName << " address is " << this->addr.houseNum << " " << this->addr.streetName << endl;
}

HiddenData::HiddenData(){
    //constructor to init all our vals
    //like a "good" program would do
    addr.streetName = "Willow St";
    addr.houseNum = 999;
    addr.zip = 82007;
    SSnum = 555324490;
    phoneNum = 5550123;

}
