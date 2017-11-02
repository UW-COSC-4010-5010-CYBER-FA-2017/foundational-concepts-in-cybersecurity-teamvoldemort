#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
  int level=0;
  printf("enter password:\n");
  string pass;
  cin >> pass;
  printf("entered %s\n",pass.c_str());
  if(pass=="admin"){
    level=2;
  }else{
    level=1;
  }

  if(level>1){
    printf("enabling admin capabilities\n");

  }else{
    printf("you have normal capabilities\n");

  }
  return 0;
}
