#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>

 

int main()

{

    pid_t pid;
    pid = fork();
    if( pid < 0){
	perror("fork");
    }
    if(0 == pid){
	int exe = execl("/usr/bin/vi","vi","/osCode/test.txt","NULL");
	if(exe == -1){
		perror("execl");}
    }else if(pid > 0){
	while(1){}
    }



    return 0;

}