#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h> //shared memory
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>   /* For O_* constants */
#define MAX_LEN 10000
struct region {        /* Defines "structure" of shared memory */
    int len;
    char buf[MAX_LEN];
};

int main(){
  struct region *rptr=(region*)malloc(sizeof(region));//STOP FUCKING FORGETTING THIS!!!
  void* rptrSpac;

  printf("rptr->len= %d\n",rptr->len);
  rptr->len = 42;
  printf("rptr->len= %d\n",rptr->len);

  /* Create shared memory object and set its size */
  int fd = shm_open("/myregion", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

  if (fd == -1){
      printf("shm_open err\n");/* Handle error */
      return 0;
  }
  if (ftruncate(fd, sizeof(struct region)) == -1){
      printf("ftruncate err\n");/* Handle error */
      return 0;
  }

  /* Map shared memory object */
  rptrSpac = mmap(NULL, sizeof(struct region), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  memcpy(rptrSpac,rptr,sizeof(rptr));
  if (rptr == MAP_FAILED){
    printf("mmap err\n");/* Handle error */
    return 0;
  }

  /* Now we can refer to mapped region using fields of rptr;
     for example, rptr->len */
   int pid = fork();
   if (pid == 0) {
     printf("Child PID: %d\n",getpid());
     printf("Child read msg: %d\n", rptr->len);
     rptr->len=59;
     memcpy(rptrSpac,rptr,sizeof(rptr));
     printf("Child read msg: %d\n", rptr->len);
   } else {
     printf("Parent PID: %d\n",getppid());
     printf("Parent read int: %d\n", rptr->len);
     sleep(2);
     printf("After 1s, parent int is: %d\n", rptr->len);
     //kill em
     kill(pid, SIGKILL);
   }
  return 0;
}
