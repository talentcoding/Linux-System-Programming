#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int x = 0;
#define MAX 100

void *print_even(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (x >= MAX)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (x % 2 == 0)
        {
            printf("Even: %d\n", x);
            x++;
        }

        pthread_mutex_unlock(&mutex);
        usleep(100); // reduce CPU usage
    }
    return NULL;
}

void *print_odd(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (x >= MAX)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (x % 2 != 0)
        {
            printf("Odd: %d\n", x);
            x++;
        }

        pthread_mutex_unlock(&mutex);
        usleep(100);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, print_even, NULL);
    pthread_create(&t2, NULL, print_odd, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}

