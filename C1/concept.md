## C1 - Process Isolation
p2-1 demonstrates process isolation through the use of shared memory between processes. The good example successfully demonstrates a method whereby, in order to share information between a parent and child process, the program maps a segment of memory using mmap() and sets appropriate permissions so that other processes can ACCESS the memory, but they wont know the address of the memory space so other processes cannot edit that memory. The bad example demonstrates using shm_open in order to create a shared memory segment using and improper amount of permissions. These permissions thus enable a separate process(here we use evil.c) to read and overwrite that shared memory process. If done at the opportune time, then the child process will only read the intercepted message written by evil.c and not the intended message written by the parent process.
![when you figure out dance](../memes/process-isolation)

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
