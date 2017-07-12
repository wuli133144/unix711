#include"../inc/common.h"
#include<sys/socket.h>

int pipe_fd(int fd[2]){
    return socketpair(AF_UNIX,SOCK_STREAM,0,fd);
}

#include<sys/un.h>

#define offset(type mem)  ((int )&(((type *)&0)->mem))

int main(){
    
   int fd;
   int size;
   struct sockaddr_un un;
   un.sun_family=AF_UNIX;
   SCPY(un.sun_path,"foo.socket");
   if((fd=socket(AF_UNIX,SOCK_STREAM,0))<0){
       err_dump("socket error!");
   }
    size=offset(struct sockaddr_un ,sun_path)+strlen(un.sun_path);
    if(bind(fd,(struct sockaddr *)&un,size)<0){
                err_dump("bind error!");
    }
    printf("bind error!");
   

    return 0;
}