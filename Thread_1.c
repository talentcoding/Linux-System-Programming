#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>


void *function1()
{
	int i=0, count=0;
	for(i=0;i<10;i++)
	{
		printf("In thread function1 \n");
		count++;
	}
	printf("count =%d \n", count);
}

int main()
{

	pthread_t t1;
	pthread_create(&t1,NULL,function1,NULL);
	pthread_join(t1,NULL);
}

