#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
long int fact(int n)
{
	long int fac=1;
	if(n!=0)
	{
			  for(int i = 1; i <=n; i++)
    {
        fac *= i;
    }
    return fac;
	}
	else
	return 1;
}
int fd1[2];
int terms,x;
void* input(void* args)
{
printf("Enter the number of  terms for the sequence : ");
scanf("%d",&terms);
write(fd1[1], &terms, sizeof(terms));	
close(fd1[1]);
}
void* generate(void* args)
{
long int digit;
read(fd1[0], &terms, sizeof(terms));
int a;
	for(int i=0;i<terms;i++)
	{
		digit=(fact(2*i)/(fact(i+1)*fact(i)));
		printf("%ld , ",digit);
	}
	close(fd1[0]);
}
int main()
{
clock_t start , end;
pthread_t tid1;
pthread_t tid2;
int rv1,rv2;
int terms;
pipe(fd1);
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
