# Part 2 Section 1
Use linux processes and shared memory to demonstrate process isolation and domain separation.
Good example will allow child process to read_only parent memory, but not external programs.
Bad example will allow both the child process and external programs to read and write parent memory in a bad way.

### Knowledge Links
* [Find all RW mem address' of a process](https://stackoverflow.com/questions/5030350/how-to-find-all-read-write-memory-address-of-a-process-in-linux-unix-with-c-c)
* [Get address of heap](https://stackoverflow.com/questions/3565232/how-to-programmatically-get-the-address-of-the-heap-on-linux)
* [Understanding proc id maps](https://stackoverflow.com/questions/1401359/understanding-linux-proc-id-maps)
* [proc(5) man](http://man7.org/linux/man-pages/man5/proc.5.html)
* [shared mem](http://menehune.opt.wfu.edu/Kokua/More_SGI/007-2478-008/sgi_html/ch03.html)
* [shm_open](http://man7.org/linux/man-pages/man3/shm_open.3.html)
* [shm_open2](http://pubs.opengroup.org/onlinepubs/009695399/functions/shm_open.html)
* [shm_open ex](http://www.cse.psu.edu/~deh25/cmpsc473/notes/OSC/Processes/shm.html)
