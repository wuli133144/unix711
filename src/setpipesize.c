
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


int main(){
  
  int pipe_fd[2];
  Pipe(pipe_fd);


  //fcntl(pipe_fd[0],F_SETPIPE_SZ,10000);
    
    if(pipe_fd[1]!=STDOUT_FILENO){
        dup2(pipe_fd[1],STDOUT_FILENO);
        Close(pipe_fd[1]);
    }


  
    return 0;
}