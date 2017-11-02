#include <iostream>
#include "hidden.cpp"

using namespace std;

// use and show features of HiddenData class
int main(){
  HiddenData ex;

  cout << "Now I want to see what the SS# is\n";
  ex.getSSnum();
  try{
    //cout << "Show me the SS dammit" << ex.SSnum << endl;
    //^^^wont let me compile
  }catch(const exception&){
    cout << "ok i guess I cant view the SS" << endl;
  }

  cout << "Now I want to see what the phone number is" << endl;
  cout << "***-***-" << ex.getPhoneNum() << endl;

  cout << "Whatever... So will you let me call them?" << endl;
  ex.callNumber();

  cout << "HA! you showed me their number, how bout their address?\n";

  ex.printAddr();
}
