
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

void  hand_func(int para){
      printf("sigpipe signal kill");
      err_dump("write");
      return;
}

int main(){
   
     
     pid_t pid;
     int status;
     int pip[2];
     Pipe(pip);
     char buffer[BUFSIZE];
     bzero(buffer,BUFSIZE);
     close(pip[0]);//close read port file
     SCPY(buffer,"wuyujie ku!")

     switch((pid=vfork()))
     {
         //read buffer
      case 0:{
           Close(pip[0]);//close read port
           signal(SIGPIPE,hand_func);
           
           write(pip[1],buffer,BUFSIZE);//可能向本进程发送sigpipe信号
          //读取管道内容时是空数据，唤醒写管道的进程，但是写管道阻塞了
           printf("hwllo !");
           exit(0);
      }
      default:{
          //write
          
          Close(pip[0]);//close read port file
          wait(&status);
          //read(pip[0],buffer,BUFSIZE);
          //write(stdout,buffer,BUFSIZE);
          return 0;
      }

     }
     


    return 0;
}