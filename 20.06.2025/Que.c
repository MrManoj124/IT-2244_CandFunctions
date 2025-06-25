Q1).Write a C program that creates two threads. Each thread should print 
a message indicating it is running. The main thread should wait for both 
threads to finish before exiting.

Q2).Write a program to create 5 threads. Each thread should print its thread
ID and then exit. The main thread should join all threads and print a 
completion message.

Q3).Write a program that creates a thread which prints numbers from 1 to 10 
with a 1-second delay between each number.The main thread should wait for 
this thread to finish.

Q4).Create two threads where one thread increments a global counter 100 times
and the other thread decrements the same counter 100 times. 
Print the final value of the counter after both threads finish.

Q5)Implement a thread function that takes an integer argument, squares it,
and returns the result to the main thread using pthread_exit and pthread_join.


//01  vi Question1.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//function to be executed by thread
void* print_message(void* arg)
{
	char* message=(char*)arg;
	printf("%s\n",message);
	return NULL;
	
}

int main()
{
	pthread_t thread1,thread2;
	
	//create first thread
	
	pthread_create(&thread1,NULL,print_message,"Thread 01 is Running...");
	
	
	//create second thread
	pthread_create(&thread2,NULL,print_message,"Thread 02 is Running...");
	
	//waiting for both thread to finish
	
	pthread_join(thread1,NULL);
	sleep(2);
	pthread_join(thread2,NULL);
	exit(1);
	
	printf("Both thread completed\n");
	return 0;
	
}


#include<stdio.h>
#include<stdlib.h>

void* thredFunc(void* arg)
{
	int threadNum=(int*)arg;
	printf("Thread %d is running.\n", threadNum);
	return NULL;
}

int main(){
	pthread_t threads[2];
	int t1_id=1, t2_id=2;
	
	pthread_create(&threads[i], NULL, thredFunc, &t1_id);
	for(int i=0; i<2; i++){
		pthread_join(threads[i], NULL);
	}
	return 0;
}



//Question2
#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunction, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed.\n");
    return 0;
}




//Question3
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* printNumbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1); // 1-second delay
    }
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, printNumbers, NULL);
    pthread_join(thread, NULL);

    return 0;
}



//Question4
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t incThread, decThread;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&incThread, NULL, increment, NULL);
    pthread_create(&decThread, NULL, decrement, NULL);

    pthread_join(incThread, NULL);
    pthread_join(decThread, NULL);

    printf("Final counter value: %d\n", counter);
    pthread_mutex_destroy(&lock);
    return 0;
}





//Question5
#include <stdio.h>
#include <pthread.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int result = num * num;
    pthread_exit((void*)result);
}

int main() {
    pthread_t thread;
    int num = 5;
    int* result;

    pthread_create(&thread, NULL, square, &num);
    pthread_join(thread, (void**)&result);

    printf("Square of %d is %d\n", num, (int)result);
    return 0;
}


//Question 01:
#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg) {
    int threadNum = *(int*)arg;
    printf("Thread %d is running.\n", threadNum);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int t1_id = 1, t2_id = 2;

    pthread_create(&t1, NULL, threadFunc, &t1_id);
    pthread_create(&t2, NULL, threadFunc, &t2_id);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished.\n");
    return 0;
}
//Question 02:
#include <stdio.h>
#include <pthread.h>

void* printThreadID(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, printThreadID, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All 5 threads have finished.\n");
    return 0;
}
//Question 03:
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* printNumbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);  // Sleep for 1 second
    }
    return NULL;
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, printNumbers, NULL);
    pthread_join(t, NULL);

    printf("Number printing thread finished.\n");
    return 0;
}
//Question 04:
#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 1000; i++) {
        counter++;
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 1000; i++) {
        counter--;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);
    return 0;
}
//Question 05:
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int)); //Allocate memory on the heap to store an integer.result points to this allocated memory.
    *result = num * num;  //Store the result in the allocated memory.
	//function used by a thread to terminate itself and optionally return a value (retval) to any thread that joins it.
    pthread_exit(result); //Exit the thread and return the pointer result to the caller.
}

int main() {
    pthread_t t;
    int num = 5;

    pthread_create(&t, NULL, square, &num);

    int* res; //Declare a pointer res to receive the result
    pthread_join(t, (void**)&res);//pthread_join stores the thread's return value (a void*) in res.

    printf("Square of %d is %d\n", num, *res);
    free(res); //Free the memory allocated by the thread to avoid memory leaks.
    return 0;
}


