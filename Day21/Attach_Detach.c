//Attach
//writer
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

#define Shared_size 1024 // Size of Shared memory

int main()
{
	key_t key = ftok("Manorooban", 87); //Generate unique key
	int shmid=shmget(key, Shared_size, IPC_CREAT | 0666); //Create a shared memory segment
	if(shmid=-1)
	{
		perror("Shared_get");
		exit(1);
	}
	
	char * shmaddr=(char*) shmat(shmid,NULL, 0); //Attach to shared memory
	if(shmaddr == (char*) -1)
	{
		perror("Shared_attach");
		exit(1);
	}
	
	printf("Data written in memory : %s \n", shmaddr);
	
	shmdt(shmaddr); //Detach from shared memory
	
	return 0;
}


//Detach
//Reader
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define Shared_size 1024

int main()
{
	key_t key = ftok("shmfile",87);
	int shmid=shmget(key, Shared_size, IPC_CREAT | 0666);
	if(shmid=-1)
	{
		perror("Segement");
		exit(1);
	}
	
	char* shmaddr = (char*) shmat(shmid, NULL, 0);
	if(shmaddr == (char*)-1)
	{
		perror("shmat");
		exit(1);
	}
	printf("data read from memory : $s\n",shmaddr);
	shmdt(shmaddr);
	shmctl(shmid,IPC_RMID,NULL);
}