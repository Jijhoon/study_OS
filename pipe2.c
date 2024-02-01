#include<signal.h>
#include<unistd.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
int count;

void main(){
	int p[2];
	int pipe_size;
	char c = 'x';
	if(pipe(p) == -1){
		perror("pipe call");
		exit(1);
	}
	pipe_size = fpathconf(p[0], _PC_PIPE_BUF);
	printf("Maximum size of write to pipe: %d bytes \n", pipe_size);
	while(1){
		write(p[1], &c, 1);
		if((++count % 1024) == 0)
			printf("%d characters in pipe \n", count);

		if(pipe_size == count)
			break;
	}
}

