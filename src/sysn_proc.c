#include"../inc/common.h"



#define BUFSIZE  1024


/*@main start@*/
int main(){
     
     int n,para1,para2;
     char line[BUFSIZE];
     while((n=read(STDIN_FILENO,line,BUFSIZE))>0){
         line[n]=0;

         if(sscanf(line,"%d%d",&para1,&para2)==2){
             sprintf(line,"%d\n",para1+para2);
             n=strlen(line);
             if(write(STDOUT_FILENO,line,n)!=n){
                 err_dump("write error!");
             }
         }else{
              if(write(STDOUT_FILENO,"invalid args\n",strlen("invalid args\n"))!=strlen("invalid args\n")){
                  return 0;
              }
         }
     }
    return 0;
}
/*@main end@*/