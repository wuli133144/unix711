#include"../inc/common.h"


/*@sig hand start@*/
static void sig_hand(int s){
    fprintf(stderr,"errno=%s\n",strerror(s));
    return;
}
/*@sig hand end@*/


int main(){

   
   pid_t pid;
   char line[BUFSIZE];
   int size;
   
   int pipe_w[NR_PIPE];
   int pipe_r[NR_PIPE];
   
   bzero(line,BUFSIZE);

    //create pipe start 
    Pipe(pipe_r);
    Pipe(pipe_w);
    // create pipe end
     
   if(signal(SIGPIPE,sig_hand)==SIG_ERR){
       err_dump("signal pipe error");
   }
   

   pid=Fork();

   if(pid==0){//child
        
      Close(pipe_w[1]);
      Close(pipe_r[0]);
      
      dup2_stdin(pipe_w[0]);
      dup2_stdout(pipe_r[1]);
      
      execl("./proc","proc",0);
      
       exit(0);
   }else{//parent
     
      
      Close(pipe_w[0]);
      Close(pipe_r[1]);
      
      while((fgets(line,BUFSIZE,stdin))!=nullptr){
             size=strlen(line);//len   
             
             write(pipe_w[1],line,size);

             read(pipe_r[0],line,size);

      }


       return 0;
   }

}