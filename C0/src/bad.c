/**
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 *
 * modifications by dheller@cse.psu.edu, 31 Jan. 2014
 * http://www.cse.psu.edu/~deh25/cmpsc473/notes/OSC/Processes/shm.html
 *
 * Further modified by Rafer Cooley
 * for demonstrating a bad example of domain separation
 * and process isolation
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

void display(char *prog, char *bytes, int n);
void meRead(const char *name);
void meWrite(const char *name);

int main(void)
{
  const char *name = "/anyone-can-see-me";	// file name

  int pid = fork();
  if(pid==0){
    //child proc
    sleep(4);
    printf("reading from shared mem\n");
    meRead(*name);
  }else{
    //parent proc
    printf("writing to shared mem\n");
    meWrite(*name);
    printf("sleeping\n");
  }

  printf("ending\n");

  return 0;
}

void display(char *prog, char *bytes, int n){
  printf("display: %s\n", prog);
  for (int i = 0; i < n; i++){
    printf("%02x%c", bytes[i], ((i+1)%16) ? ' ' : '\n');
    //printf("%c%c", bytes[i], ((i+1)%16) ? ' ' : '\n');
  }
  for (int i = 0; i < n; i++){
    //printf("%02x%c", bytes[i], ((i+1)%16) ? ' ' : '\n');
    printf("%c%c", bytes[i], ((i+1)%16) ? ' ' : '\n');
  }
  printf("\n");
}

void meRead(const char *name){
  const char *name2 = "/anyone-can-see-me";	// file name
  const int SIZE = 4096;		// file size
  int shm_fd;		// file descriptor, from shm_open()
  char *shm_base;	// base address, from mmap()

  /* open the shared memory segment as if it was a file */
  shm_fd = shm_open(name2, O_RDONLY, 0666);
  if (shm_fd == -1) {
    printf("read: Shared memory failed: %s\n", strerror(errno));
    exit(1);
  }

  /* map the shared memory segment to the address space of the process */
  shm_base = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  if (shm_base == MAP_FAILED) {
    printf("read: Map failed: %s\n", strerror(errno));
    // close and unlink?
    exit(1);
  }

  /* read from the mapped shared memory segment */
  display("read", shm_base, 64);	// first as bytes, then as a string
  printf("%s\n", shm_base);

  printf("removing segment from addr space\n");
  /* remove the mapped shared memory segment from the address space of the process */
  if (munmap(shm_base, SIZE) == -1) {
    printf("read: Unmap failed: %s\n", strerror(errno));
    exit(1);
  }

  printf("closing shared mem\n");
  /* close the shared memory segment as if it was a file */
  if (close(shm_fd) == -1) {
    printf("read: Close failed: %s\n", strerror(errno));
    exit(1);
  }

  printf("removing segment from FS\n");
  /* remove the shared memory segment from the file system */
  if (shm_unlink(name) == -1) {
    printf("read: Error removing %s: %s\n", name, strerror(errno));
    exit(1);
  }
}

void meWrite(const char *name){
  const char *name2 = "/anyone-can-see-me";	// file name
  const int SIZE = 4096;		// file size

  const char *message = "This is the correctly written message";

  int shm_fd;		// file descriptor, from shm_open()
  char *shm_base;	// base address, from mmap()
  char *ptr;		// shm_base is fixed, ptr is movable

  /* create the shared memory segment as if it was a file */
  shm_fd = shm_open(name2, O_CREAT | O_RDWR, 0666);
  if (shm_fd == -1) {
    printf("write: Shared memory failed: %s\n", strerror(errno));
    exit(1);
  }

  /* configure the size of the shared memory segment */
  ftruncate(shm_fd, SIZE);

  /* map the shared memory segment to the address space of the process */
  shm_base = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (shm_base == MAP_FAILED) {
    printf("write: Map failed: %s\n", strerror(errno));
    // close and shm_unlink?
    exit(1);
  }

  //display("prod", shm_base, 64);
  ptr = shm_base;
  ptr += sprintf(ptr, "%s", message);
  display("write", shm_base, 64);

  /* remove the mapped memory segment from the address space of the process */
  if (munmap(shm_base, SIZE) == -1) {
    printf("write: Unmap failed: %s\n", strerror(errno));
    exit(1);
  }

  /* close the shared memory segment as if it was a file */
  if (close(shm_fd) == -1) {
    printf("write: Close failed: %s\n", strerror(errno));
    exit(1);
  }
}
