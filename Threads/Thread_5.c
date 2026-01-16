// This program will create to 2 threads and executes parallel both at same time adding safety return
// need to compile with gcc Thread_4.c -pthread


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


int x=20;

void *function1()
{
	printf("Thread in function1\n");
	x++;
        sleep(2);
	printf("x=%d\n",x);       
}


void *function2()
{
	printf("Thread in function2\n");
        sleep(2);
	printf("x=%d\n",x);       
}

int main()
{

	pthread_t t1,t2;
	if(pthread_create(&t1,NULL,function1,NULL)!=0)
	{
		return 1;
	}
	if(pthread_create(&t2,NULL,function2,NULL)!=0)
	{
		return 2;
	}
	if(pthread_join(t1,NULL)!=0)
	{
		return 3;
	}
	if(pthread_join(t2,NULL)!=0)
	{
		return 4;
	}
}
