
#include"../inc/common.h"

/*@pipe() start@*/
int Pipe(int fd[2]){
     int ret;
     if((ret=pipe(fd))==-1){
         err_dump("pipe error");
     }
     return ret;
}

/*@pipe()end@*/

#define BUFSIZE 1024

int main(){
   
     
     pid_t pid;
     int status;
     int pip[2];
     Pipe(pip);
     char buffer[BUFSIZE];
     bzero(buffer,BUFSIZE);
     
     SCPY(buffer,"wuyujie ku!")

     switch((pid=Fork()))
     {
         //read buffer
      case 0:{

           write(pip[1],buffer,BUFSIZE);

          //读取管道内容时是空数据，唤醒写管道的进程，但是写管道阻塞了
           printf("hwllo !");
           exit(0);
      }
      default:{
          //write
          wait(&status);
          read(pip[0],buffer,BUFSIZE);
          write(stdout,buffer,BUFSIZE);
          return 0;
      }
     }
     


    return 0;
}