#include <stdio.h>
#include <stdlib.h>

//README: this shows a couple ways to divide by two very complicatedly

int main (int argc, char* argv[]) {
  int *x = (int*)malloc(sizeof(int));
  *x=200;

  //one example
  printf("%c%c%d%c%c%c%c%c%c%c%d\n",0x78,0x3d,x,0x20,0x2d,0x2d,0x20,0x2a,0x78,0x3d,*x);
  asm("AA:\nNOP");//while loop through jmping
  if(*x>(int)5){
    *x=*x/2;//desired operation
    //asm("sar $1,%1":"=r"(*x):"n"(*x));//<<<---- couldn't get this working
    printf("%c%c%d%c%c%c%c%c%c%c%d\n",0x78,0x3d,x,0x20,0x2d,0x2d,0x20,0x2a,0x78,0x3d,*x);//teehee
    asm("NOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\njmp AA");
  }

  //another example
  printf("--next example--\n");
  *x=200;
  void* i=0;
  while(*x>5){
    *x>>=1;
    printf("%c%c%d%c%c%c%c%c%c%c%d\n",0x78,0x3d,x,0x20,0x2d,0x2d,0x20,0x2a,0x78,0x3d,*x);//teehee
  }
  return 0;
}
