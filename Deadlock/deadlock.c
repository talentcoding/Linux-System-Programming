// here accuquring the lock pthread_mutex_lock(&mutex); 2 times leads to deadlock

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//#define THREADS 4
#define ITERATIONS 100000000

pthread_mutex_t mutex;
int x = 0;

void *function1(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        pthread_mutex_lock(&mutex);

        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t t[8];

    pthread_mutex_init(&mutex, NULL);
	int i=1;
    // Create threads
    for ( i = 1; i <= 8; i++)
    {
        if (pthread_create(&t[i], NULL, &function1, NULL) != 0)
        {
            perror("pthread_create");
            return 1;
	}
    

    printf("Threads created =%d\n",i);
    }
    // Join threads
    for (i = 1; i <= 8; i++)
    {
        if (pthread_join(t[i], NULL) != 0)
        {
            perror("pthread_join");
            return 2;
        }
    
    
    printf("Threads finished=%d\n",i);
    }

    pthread_mutex_destroy(&mutex);

    printf("value of x = %d\n", x);

    return 0;
}

