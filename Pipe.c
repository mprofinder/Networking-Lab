#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main(){


	int pipe1[2],pipe2[2],pipe_id,i,len;
	char msg1[50],msg2[50],buffer[100],c;

	pipe(pipe1);
	pipe(pipe2);
	pipe_id = fork();

	if(pipe_id == 0){

		close(pipe1[0]);
		close(pipe2[1]);
		printf("Type Message from Client to Server : ");
		scanf("%s",msg1);
		
		write(pipe1[1],msg1,sizeof(msg1));
		read(pipe2[0],buffer,sizeof(buffer));
		
		printf("Server Response : %s\n",buffer);
		
		}


	if(pipe_id > 0){

		close(pipe1[1]);
		close(pipe2[0]);
		
		len=read(pipe1[0],buffer,sizeof(buffer));
		
		printf("Client Response: %s\n",buffer);
		printf("Type Message from Server to Client : ");
		scanf("%s",msg2);
		
		write(pipe2[1],msg2,sizeof(msg2));
		
		}

	printf("\n");
	
}


