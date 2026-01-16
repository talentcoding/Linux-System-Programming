// This program will create to 2 threads but not create parallel and execute parallel it will execute sequenctailly 
// First t1 thread create and execute and next t2 thread will create and executed
// need to compile with gcc Thread_2.c -pthread


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


void *function1()
{
	printf("Thread in function1 \n");
        sleep(2);
	printf("End in function1\n ");       
}

int main()
{

	pthread_t t1,t2;
	pthread_create(&t1,NULL,function1,NULL);
	pthread_join(t1,NULL);
	
	pthread_create(&t2,NULL,function1,NULL);
	pthread_join(t2,NULL);
}
