

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


/**@fork end@*/

/*@close start@*/
int Close(int fd){
    int ret;
    if((ret=close(fd))!=0){
        err_dump("close");
    }
    return ret;
}
/*@close end@*/



int main()
{
int pipe_fd[2];
pid_t pid;
char read_buf[4096];
char write_buf[4096];

int writenum;
int rnum;
memset(read_buf,0,sizeof(read_buf));
Pipe(pipe_fd);

    if((pid=Fork()) == 0)
    {    
          Close(pipe_fd[1]);//close write port
          while(1){
              rnum=read(pipe_fd[0],read_buf,sizeof(read_buf));
              if(rnum==0){
                  printf("all write port closed!");
                  break;
              }
              
          }
          Close(pipe_fd[0]);//close read port
          exit(0);

    }else{ 
             Close(pipe_fd[0]);//close read port
             bzero(write_buf,sizeof(write_buf));

             writenum=write(pipe_fd[1],write_buf,sizeof(write_buf));
              if(writenum==-1){
                  err_dump("write error!");
              }
              sleep(15);
              printf("will close the last write port!");
              
              Close(pipe_fd[1]);
              sleep(2);
              return 0;
    }