#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t childpid;
	int i;
	childpid = fork();
	if(childpid > 0){
		printf("parents pid: %d\n", getpid());
		sleep(2);
		printf("parents termination\n");
		exit(0);
	}
	else if(childpid == 0){
		printf("child\n");
		for(i = 0; i < 10; i++){
			printf("child pid: %d, parents pid: %d\n", getpid(), getppid());
			sleep(1);
		}
		printf("child termination");
		exit(0);
	}
	else{
		return -1;
	}
	return 0;
}

