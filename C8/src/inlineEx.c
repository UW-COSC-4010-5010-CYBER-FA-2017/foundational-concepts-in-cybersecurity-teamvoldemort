//*
#include <stdio.h>
#include <stdlib.h>

//extern int x; //can be used instead of malloc'ing each var
int main (int argc, char* argv[]) {
  //asm ("bsrl %1, %0" : "=r" (position) : "r" (number));
  int *x = (int*)malloc(2);
  *x=0;

  asm("AA:");
  if(*x<(int)5){
    *x=*x+1;
    printf("x=%d -- *x=%d\n",x,*x);
    asm("jmp AA");
    //goto AA;
  }
  return 0;
}
//*/
/*
// -->>https://stackoverflow.com/questions/37355000/os-x-undefined-symbols-for-architecture-i386-when-using-inline-assembly-in-c

void* print_stacktrace()
{
    void *addr;
    asm("mov %%esp, %0;" : "=r" (addr));
    return addr;
}

int main (int argc, char *argv[])
{
    printf("%p\n", print_stacktrace());
    return 0;
}
//*/
