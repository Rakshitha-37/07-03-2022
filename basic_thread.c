#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *myturn(void *ptr) //Thread1 handler function
{
	while(1)
	{
		printf("My thread1 handle\n");
		printf("Thread1 ID = %ld, thread1 message = %s\n", pthread_self(), (char *)ptr);
		sleep(1);
	}
}

void *Yourturn(void *ptr) //Thread2 handler function
{
	while(1)
	{
		printf("My thread2 handle\n");
		printf("Thread2 ID = %ld, thread2 message = %s\n", pthread_self(), (char *)ptr);
		sleep(1);
	}
}

int main()
{
	pthread_t tid1, tid2;
	char *msg1 = "Myturn";
	char *msg2 = "Yourturn";
	pthread_create(&tid1, NULL, &myturn, (void *)msg1); //To create thread
	pthread_create(&tid2, NULL, &Yourturn, (void *)msg2);

	pthread_join(tid1, NULL);//To wait for the thread to complete its execution
	pthread_join(tid2, NULL);
}
