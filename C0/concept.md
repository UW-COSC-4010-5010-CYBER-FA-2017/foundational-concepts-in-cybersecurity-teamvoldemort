## C0 - Domain Separation
p2-1 demonstrates domain separation by prohibiting other processes(the other domains) from accessing shared memory between a child and parent process. This separation prevents other processes from affecting the shared memory. The bad example demonstrates a bad way to utilize shared memory by creating a shared memory block for the child and parent processes, but this memory is also available from the rest of the system so other processes could have an effect on the shared memory and potentially cause problems.
![spidey separation](../memes/domain-seperation.jpg)

*good.cpp*
```
...
int protection = PROT_READ;

// The buffer will be shared (meaning other processes can access it), but
// anonymous (meaning third-party processes cannot obtain an address for it),
// so only this process and its children will be able to use it:
int visibility = MAP_ANONYMOUS | MAP_SHARED;

return mmap(NULL, size, protection, visibility, 0, 0);
...
```

*bad.c*
```
...
/* open the shared memory segment as if it was a file */
shm_fd = shm_open(name2, O_RDONLY, 0666);
...

/* map the shared memory segment to the address space of the process */
shm_base = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
...
```
