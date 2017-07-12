

#include<stdio.h>
#include<unistd.h>



#define BUFSIZE  1024
int main(){
  
  int n,int1,int2;
  char line[BUFSIZE];

  while((n=read(STDIN_FILENO,line,BUFSIZE))<0){
          line[n]='\0';
          sscanf(line,"%d%d",&int1,&int2);
          sprintf(line,"%d\n",int1+int2);
          n=strlen(line);
          if(write(STDOUT_FILENO,line,n)<0){
              err_dump("write\n");
          }
    }
    exit(0);
    return 0;
}