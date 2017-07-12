#include"../inc/common.h"

#include<sys/socket.h>
#include<sys/un.h>



int ser_listen(const char *name){

  
  int fd,len,err,rval;
  struct sockadrr_un un;
  if(strlen(name)>sizeof(un.sun_pth)){
      errno=ENAMETOOLONG;
      return -1;
  }
  if((fd=socket(AF_UNIX,SOCK_STREM,0))<0){
      err_dump("socket error!");
  }
  unlink(name);
  bzero(un,sizeof(un));
  un.sun_family=AF_UNIX;
  strcpy(un.sun_pth,name);
  len=offsetof(struct sockaddr_un ,sun_path)+strlen(name);
  if(bind(fd,(struct sockaddr *)&un,len)<0){
      exit(1);
  }
  if(listen(fd,QLEN)<0){
      goto:err;
  }
   err:
    return 0;

}