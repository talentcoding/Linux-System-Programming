// This program will create tsic mutex 
// need to compile with gcc Mutex_example.c -pthread


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


pthread_mutex_t mutex;
int x=0;

void *function1()
{
	int i=0;
	for(i=0;i<10000000;i++)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
}


int main()
{

	pthread_t t1,t2;

	pthread_mutex_init(&mutex,NULL);
	if(pthread_create(&t1,NULL,function1,NULL)!=0)
	{
		return 1;
	}
	if(pthread_create(&t2,NULL,function1,NULL)!=0)
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
	
	pthread_mutex_destroy(&mutex);
		
	printf("value x=%d\n",x);

}
