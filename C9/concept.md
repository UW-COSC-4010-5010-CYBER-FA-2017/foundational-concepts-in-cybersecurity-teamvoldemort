## C9 - Minimization
p2-2 demonstrates good and bad examples of minimization, with the good example creating a minimal server with one open port while the bad example opens up 3 different ports for connection. These ports are unnecessary and one is an administration port, which should be password protected but is not.
![ricks minimal portal](../memes/minimization-rickmorty.jpg)

*ex.cpp*
```
...
portno = 18000;
...
```

*non.cpp*
```
...
portno = 18001;
...
portno = 18000;
...
```
