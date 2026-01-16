// This program will create simple  mutex with 4 threads 
// need to compile with gcc Mutex_example_1.c -pthread


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


pthread_mutex_t mutex;
int x=0;

void *function1()
{
	int i=0;
	for(i=0;i<100000000;i++)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
}


int main()
{

	pthread_t t1,t2,t3,t4;

	pthread_mutex_init(&mutex,NULL);
	if(pthread_create(&t1,NULL,function1,NULL)!=0)
	{
		return 1;
	}
	if(pthread_create(&t2,NULL,function1,NULL)!=0)
	{
		return 2;
	}
	
	if(pthread_create(&t3,NULL,function1,NULL)!=0)
	{
		return 3;
	}

	
	if(pthread_create(&t4,NULL,function1,NULL)!=0)
	{
		return 4;
	}

	if(pthread_join(t1,NULL)!=0)
	{
		return 5;
	}
	if(pthread_join(t2,NULL)!=0)
	{
		return 6;
	}

	
	if(pthread_join(t3,NULL)!=0)
	{
		return 7;
	}

	
	if(pthread_join(t4,NULL)!=0)
	{
		return 8;
	}

	pthread_mutex_destroy(&mutex);
		
	printf("value x=%d\n",x);

}
