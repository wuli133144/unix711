


#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <signal.h>
#include<pthread.h>
#include<errno.h>
#include<pwd.h>
#include<grp.h>


#define BUFSIZE              1024
#define NR_PIPE              2

#define  nullptr             0



#define   PARA    (int argc,char **argv) 

#define err_exit(e) \
do{                 \
     perror(e);     \
     exit(0);       \
}while(0)

#define err_dump(err) do{                    \
             fprintf(stderr,"%s %s",strerror(errno),err);\
             exit(0);                            \
}while(0)


#ifdef  __SCP__N
   #define SCPYN(a, b) strncpy(a, b, sizeof(a))
#else
    #define SCPY(a,b)   strcpy(a,b);
#endif


#define EVER ;;

/*@getpwuid get user info@*/
struct  passwd *Getpwuid(int uid){
    struct passwd *pw_st=NULL;
    if((pw_st=getpwuid(uid))==NULL){
        err_exit("getpwuid");
    } 
    return pw_st;
}
/*@getpwuid end@*/


/*@skip start@*/
//find position 
static char *skip(char *start,char *op){
            while(*start&&strcpy(start,op)!=0){
                      start++;
            }
            if(*start!=0)
               start++;
  return start;
}
/*@skip end@*/

/*@getpwname get user info by username@*/
struct passwd *Getpwnam(const char *name){
     struct passwd *pw_st=NULL;
    if((pw_st=getpwnam(name))==NULL){
        err_exit("getpwuid");
    } 
    return pw_st;
}

/*@getpwname end@*/

/*@getpwent start @*/
struct passwd *Getpwent(){
     struct passwd *pw_st=NULL;
    if((pw_st=getpwent())==NULL){
        err_exit("getpwent");
    } 
    return pw_st;
}

/*@getpwent end@*/


/*@getprent start*/

 struct group * Getgrent(){
     struct group *pw_st=NULL;
    if((pw_st=getgrent())==NULL){
        err_exit("getprent");
    } 
    return pw_st;
 }


/*@getprent end@*/


/*@Fork ()start@*/

pid_t Fork(){
    int pid;
    if((pid=fork())<0){
        err_dump("fork error!");
    }
    return pid;
}


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


/*@dup2_stdin start@*/


int dup2_stdin(int fd){
    if(fd!=STDIN_FILENO){

        if(dup2(fd,STDIN_FILENO)!=STDIN_FILENO)){
            err_dump("dup2 stdin_fileno");
        }
        close(fd);
    }
    return 0;
}

/*@dup2_stdin end@*/


/*@dup2_stdout@*/
int dup2_stdout(int fd){
    if(fd==STDOUT_FILENO){
        if(dup2(fd,STDOUT_FILENO)!=STDOUT_FILENO){
            err_dump("dup2 stdout ");
        }
        close(fd);
    }
    return 0;
}


/*@dup2_stdout@*/



/*@pipe() start@*/
int Pipe(int fd[2]){
     int ret;
     if((ret=pipe(fd))==-1){
         err_dump("pipe error");
     }
     return ret;
}

/*@pipe()end@*/
