## C3 - Least Privilege
p2-3 demonstrates a least privilege proof of concept. The good example demonstrates setting different levels of capabilities based on an entered password. The bad example sets the capability level as admin level no matter the password.
![american psycho privileges](../memes/privileges-psycho.png)

*good.cpp*
```
if(pass=="admin"){
  level=2;
}else{
  level=1;
}
```

*bad.cpp*
```
if(pass=="admin"||true){
  level=2;
}else{
  level=1;
}
```
