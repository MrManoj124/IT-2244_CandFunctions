//Single thread processing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Function executed by the thread
void *helloManorooban(void *vargp) {
    sleep(1);
    printf("Hey Manorooban..! \n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    printf("Before Thread \n");

    // Create the thread
    if (pthread_create(&thread_id, NULL, helloManorooban, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("Failed to join thread");
        return 1;
    }

    printf("After Thread \n");
    return 0;
}




//Multi thread process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//Function should be executed by the thread

void* print_message(void* arg)
{
	char* message = (char *)arg;
	printf("%S\n",message);
	return NULL;
}

int main()
{
	pthread_t thread,thread1;
	

	printf("Before Threading ..\n");
	
	//create a first thread
	pthread_create(&thread,NULL,print_message,"Hey Mr_");
	//create a second thread
	pthread_create(&thread1,NULL,print_message,"Manorooban");
	
	//Joining the threads
	pthread_join(thread,NULL);
	pthread_join(thread1,NULL);
	
	printf("After the joining the threads..\n");
	return 0;
}

//Multi threading using array
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* print_message(void *arg)
{
	char* message = (char *)arg;
	printf("%s\n",message);
	return NULL;
}

int main()
{
	pthread_t threads[3];
	char* messages[]
={
	"Thread 1 Say hey Manorooban",
	"You're doing ",
	"Excellent Job"
};
for(int i=0; i<3; i++)
{
	pthread_create(&threads[i],NULL,print_message,messages[i]);
}
for(int i=0; i<3; i++)
{
	pthread_join(threads[i],NULL);
}
printf("All threads are done\n");
return 0;

}