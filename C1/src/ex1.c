//https://stackoverflow.com/questions/5656530/how-to-use-shared-memory-with-linux-in-c
// example of using shared memory b/w procs
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h> //shared memory
#include <string.h>
#include <unistd.h>

void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  //int protection = PROT_READ | PROT_WRITE;
  int protection = PROT_READ;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_ANONYMOUS | MAP_SHARED;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, 0, 0);
}

int main() {
  char* parent_message = "hello";  // parent process will write this message
  char* child_message = "goodbye"; // child process will then write this one

  void* shmem = create_shared_memory(128);

  memcpy(shmem, parent_message, sizeof(parent_message));

  int pid = fork();
  //int pid2 = fork();
  //printf ("pid1=%d pid2=%d",pid1,pid2);
  if (pid == 0) {
    printf("Child read: %s\n", shmem);
    if(!memcpy(shmem, child_message, sizeof(child_message))){
      printf("memcpy err\n");
    }
    printf("Child wrote: %s\n", shmem);

  } else {
    printf("Parent read: %s\n", shmem);
    sleep(1);
    printf("After 1s, parent read: %s\n", shmem);
  }

  kill(pid, SIGKILL);
}
