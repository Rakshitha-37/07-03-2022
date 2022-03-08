#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

char ch = 65;

void *capital(void *ptr)
{
	while(ch <= 90)
	{
		printf("Capital: %c\n", ch);
		sleep(1);
	}
}

void *small(void *ptr)
{
	while(ch <= 90)
	{
		printf("Small: %c\n", ch+32);
		ch++;
		sleep(1);
	}
}

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &capital, NULL);
	pthread_create(&thread2, NULL, &small, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
