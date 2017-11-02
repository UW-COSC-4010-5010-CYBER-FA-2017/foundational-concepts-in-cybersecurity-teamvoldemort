/*
raf3r c0oley
bad example of resource encapsulation and minimization
principles C2 and C9
C9 - expose unnecessary ports
C2 - get system loadavg info on admin port
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
  int pid = fork();
  if (pid == 0) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 18001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
             error("ERROR on binding");

    while(true){
      printf("listening on port %d\n",portno);
      listen(sockfd,5);
      clilen = sizeof(cli_addr);
      newsockfd = accept(sockfd,
                  (struct sockaddr *) &cli_addr,
                  &clilen);
      if (newsockfd < 0)
           error("ERROR on accept");
      bzero(buffer,256);
      n = read(newsockfd,buffer,255);
      if (n < 0) error("err: sok read");
      printf("Received Message: %s\n",buffer);

      std::ifstream sysInfo ("/proc/loadavg");
      sysInfo.read (buffer,255);
      n = write(newsockfd,buffer,255);
      if (n < 0) error("err: sok write");
    }


    close(newsockfd);
    close(sockfd);
  } else {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 18000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
             error("ERROR on binding");

    while(true){
      printf("listening on port %d\n",portno);
      listen(sockfd,5);
      clilen = sizeof(cli_addr);
      newsockfd = accept(sockfd,
                  (struct sockaddr *) &cli_addr,
                  &clilen);
      if (newsockfd < 0)
           error("ERROR on accept");
      bzero(buffer,256);
      n = read(newsockfd,buffer,255);
      if (n < 0) error("err: sok read");
      printf("Received Message: %s\n",buffer);
      n = write(newsockfd,"I got your message",18);
      if (n < 0) error("err: sok write");
    }


    close(newsockfd);
    close(sockfd);
  }

   return 0;
}
