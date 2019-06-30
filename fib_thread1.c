#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
int fd[2];
int terms;
void* input(void* args)
{

printf("Enter the number of  terms for the sequence : ");
scanf("%d",&terms);
write(fd[1], &terms, sizeof(terms));
printf("0 , 1 ");	
close(fd[1]);
}
void* generate(void* args)
{
int sum=0,first=0,second=1;
read(fd[0], &terms, sizeof(terms));
for(int i=0;i<(terms-2);i++)
	{
		sum=first+second;
		first=second;
		second=sum;
		printf(", %d ",sum);
	}
  close(fd[0]);
}
int main()
{
clock_t start , end;
pthread_t tid1;
pthread_t tid2;
int terms;
pipe(fd);
start = clock();
pthread_create(&tid1,0, input, NULL); 
pthread_create(&tid2,0, generate, NULL);    
pthread_join(tid1, NULL);
pthread_join(tid2, NULL);
end = clock();
double time = ((double)(end-start)) / CLOCKS_PER_SEC;
printf("Time taken : %.3f ms \n." , time * 1000 );
return 0;
}

