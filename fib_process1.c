#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>

int main()
{

	int first=0;
	int second=1;
	int sum=0;
	int terms;
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

 		for(int i=0;i<terms-2;i++)
	{
		sum=first+second;
		first=second;
		second=sum;
		printf(", %d ",sum);
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
printf("\n %d , %d " ,first,second);
       
close(fd[1]);
clock_t end2= clock();
time2= ((double) ( end2 - start2 ) ) / CLOCKS_PER_SEC;
	}
	return 0;
}
