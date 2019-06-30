#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>
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
int main()
{
		int terms;
		long int digits;
double time1 , time2;
int fd[2];
pipe(fd);

    pid_t pid=fork();
     if(pid<0)
 {
   printf("Unsuccessful  Process Creation");
   exit(0);
 } 
 if(pid>0)      //parent process
 {
clock_t start1 = clock();
 	wait(NULL);
read(fd[0], &terms, sizeof(terms));

	for(int i=0;i<terms;i++)
	{
		digits=	((fact(i+1))/(2*fact(i-1)));
	printf(" %ld , ",digits);
	}
   close(fd[0]);
  clock_t end1 = clock();
 time1= ((double) ( end1 - start1 ) )/ CLOCKS_PER_SEC ;
time1 = (double) (time1*1000);
time2= (double) (time2*1000);
printf("\n The time taken is : %.3f msec \n" , time1+time2);

 }
 if(pid==0)       //child process
	{
clock_t start2 = clock();
	printf("Enter the number of  terms for the sequence : ");
	scanf("%d",&terms);
 write(fd[1], &terms, sizeof(terms));	       
close(fd[1]);
clock_t end2= clock();
	}
	return 0;
}
