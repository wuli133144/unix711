
#include"../inc/common.h"

static void sig_hand(int);
int main(int argc,char **argv){

int pipe_fd[2];
int pipe_fd1[2];

int n;

pid_t pid;


char line[BUFSIZE];
bzero(line,BUFSIZE);


//registe sighand

if(signal(SIGPIPE,sig_handle)==SIGERR){
    err_dump("signal pipe error");
}


Pipe(pipe_fd);

pid=Fork();

if(pid==0){//child
 
 Close(pipe_fd[1]);//close write port pipe1
 Close(pipe_fd1[0]);//close read port pipe1
 
  
dup2_stdin(pipe_fd[0]);
dup2_stdout(pipe_fd1[1]);

execl("./proc","proc",NULL);

exit(0);
}else{//proc 
  
  Close(pipe_fd[0]);//close read port
  Close(pipe_fd1[1]);//close write port

  while((fgets(line,BUFSIZE,stdin))!=NULL){
          n=strlen(line);
          write(pipe_fd[1],line,n);

          if((n=read(pipe_fd1[0],line,BUFSIZE))<0){
              err_dump("read error!");
          }

          if(n=0){
              err_dump("child close pipe");
              break;
          }

          line[n]=0;
          if(fputs(line,stdout)==EOF){
             err_dump("fputs");
          }
  }
return 0;

}
}