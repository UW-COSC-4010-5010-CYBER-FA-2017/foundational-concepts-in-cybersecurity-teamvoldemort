## C8 - Simplicity
These examples show a simple way to perform an arbitrary calculation and two ways to overcomplicate that same calculation. The good way uses a simple while loop to perform the calculation, requiring only 9 lines. The bad way shows two different ways to overcomplicate this calculation. The first way uses inline assembly code to perform the while loop by jmp'ing to inline labels. The output is also encoded in hex form further obfuscating the program and decreasing readability. Inline NOP assembly instructions are also included to increase program complexity. The second bad example uses bitshifting to perform the calculation which may confuse future programmers who may need to edit the code.
![condescending kermit the coder](../memes/simplify.jpg)

*good.c*
```
int main(){
  int x =200;
  while(x>5){
    x/=2;
    printf("x=%d\n",x);
  }
}
```

*bad.c*
```
asm("AA:\nNOP");//while loop through jmping
if(*x>(int)5){
  *x=*x/2;//desired operation
  //asm("sar $1,%1":"=r"(*x):"n"(*x));//<<<---- couldnt get this working
  printf("%c%c%d%c%c%c%c%c%c%c%d\n",0x78,0x3d,x,0x20,0x2d,0x2d,0x20,0x2a,0x78,0x3d,*x);//teehee
  asm("NOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\nNOP\njmp AA");
}
...
//second bad example
*x=200;
while(*x>5){
  *x>>=1;
  printf("%c%c%d%c%c%c%c%c%c%c%d\n",0x78,0x3d,x,0x20,0x2d,0x2d,0x20,0x2a,0x78,0x3d,*x);//teehee
}
```
