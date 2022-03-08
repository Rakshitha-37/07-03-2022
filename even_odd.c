#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>


pthread_t tid[2];
int val = 10;
int data = 0;

void *even(void *ptr)
{
	do
	{
		if((data%2) == 0)
		{
			printf("Even: %d\n", data);
			data++;
		}
	}while(data <= val);
}

void *odd(void *ptr)
{
	do
	{
		if((data%2) != 0)
		{
			printf("Odd: %d\n", data);
			data++;
		}
	}while(data <= val);
}

int main()
{

	pthread_create(&tid[0], NULL, &even, NULL);
	pthread_create(&tid[1], NULL, &odd, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}

