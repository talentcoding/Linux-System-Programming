// This program will create to 2 threads and executes parallel both at same time adding safety return it will results race condition 
// need to compile with gcc Thread_6.c -pthread


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


int x=0;

void *function1()
{
	int i=0;
	for(i=0;i<100000;i++)
	{
	x++;	
	}
}


int main()
{

	pthread_t t1,t2;
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

	printf("value x=%d\n",x);

}
