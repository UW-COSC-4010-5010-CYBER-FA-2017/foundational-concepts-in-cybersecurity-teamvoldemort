#include <string>
typedef unsigned long ulong;

struct address{
  std::string streetName;
  ulong houseNum;
  ulong zip;
};

class HiddenData{
private:
  ulong SSnum;
  ulong phoneNum;

public:
  std::string fName, lName;
  address addr;
  HiddenData();
  void callNumber();// "calls" persons phone number
  bool hasSS();//contains S.S. number
  bool hasPhoneNum();
  void setSSnum(int ss);
  int getSSnum();
  void setPhoneNum(int num);
  int getPhoneNum();
  void printAddr();
};
