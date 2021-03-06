

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



void sig_handler(int sigo){
    printf("signo=%d",signo);
}

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
 
 if(signal(SIGPIPE,sig_handler)==SIG_ERR){
     fprintf(stderr,"sig error=%s",strerror(errno));
     err_dump("signal error");
 }
 if((pid=Fork())==0){
     
     printf(" close the lase read port!");
     Close(pipe_buf[0]);//close read port       
     exit(0);
 }else{
     Close(pipe_buf[0]);//close read_buf
     sleep(1);

     int ret=write(pipe_fd[1],"hello world",sizeof("hello world"));
      if(ret==-1){
          err_dump("write");
      }
       
     return 0;
 }



}