#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include"sys/types.h"
#include"wait.h"
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
void wait1(int );
void signal1(int );
int count=0;
int sm=1;
int main(int argc,char *argv[])
{
     wait1(sm);

 pid_t pid;
int rv,key=5678;
int n,i;
int sid;
int *sm,*s,rr,rp[2];
const int size=4096;
int parent=getpid();
int no=atoi(argv[1]);
int it=0;
      //   system("clear");
	printf("\n\t\tWELCOME TO KEB E-BILLING SYSTEM\n\n");
        printf("Press 1.continue  2.exit\n");
	scanf("%d",&n);
     if((sid=shmget(key,size,IPC_CREAT|0777))<0)
		{
 			perror("shmat");
			exit(0);
		}
        	sm= shmat(sid,NULL,0);
for(it=0;it<=no;it++)
{
  pid=fork();
  count++;
}


	switch(n){
 	
	case 1:printf("WELCOME ADMIN\n\n");
	//	pid=fork();		
		if(pid<0)
		{
		    fprintf(stderr,"fork not working\n",NULL);
			exit(-1);
		}
		else if(pid==0)
		{
		count--;
          	 printf("child proces\nMY PID IS %d\n",getpid());
      //   printf("MY PARENT ID IS %d\n\n",getppid());
	//system("gcc client.c");	//  execlp("gcc ","gcc client.c","NULL");
	//	system("./a.out");
	//	printf("*%s\n",sm);
	//	for(s=sm;*s!=NULL;s++)
	//	putchar(*s);
             //  system("clear");  
		printf("\n \t\t\t\t\t\tKEB E-BILLING SYSTEM \n\n\n\n");
		printf("\n\t\t\tCLIENT REQUEST=%d  (message from client process)\n",count);
		printf("\t\t\tENTER THE RR NO:\t");
		scanf("%d",&rr);
		s=sm;
		*s=(int )rr;
		if(count==0)
		{
		s++;*s=NULL;
		}	 
//		strcpy(s,rr);

		//*s++=NULL;
		shmdt(sm);
		 printf("\n\t\t\tRequest sent to server wait for Response\n");
		sleep(3);
		signal1(sm);
		exit(0);
               
	        }
		else //if(parent==getpid())
		{
		//system("clear");
	 printf("\nMESSAGE FROM SERVER PROCESS  MY ID IS:%d\n\n",getpid());
	//	execlp("gcc","gcc","server.c","NULL");
		 
	//	system("gcc server.c");

	//	system("./a.out");
	//	wait(NULL);
          //     	printf("\nPARENT EXITTING\n");
  
		wait(NULL);
		int k=0;
		while(*sm!=NULL){
		rp[k]=*sm;
		sm++;k++;}
			printf("*************************************************************************************************************");	
			printf("\n*************************************************************************************************************");	
                        for(k=0;k<2;k++) 
			printf("\n\t\t\tYOUR RR NO WAS ----->%d\n\n",rp[k]);
	
		
		shmdt(sm);
		shmctl(sid,IPC_RMID,NULL);
		



FILE *fp ;
struct cust
{
char name[40] ;
int age ;
char address[50] ;
int rr;
float cost;
};
struct cust c;
fp = fopen ( "bill.txt", "r+" ) ;
if ( fp == NULL )
{
puts ( "Cannot open file" ) ;
exit(0) ;
}
while ( fscanf ( fp, "%s %d %s %f %d", c.name, &c.age, c.address ,&c.cost,&c.rr) != EOF )
{ 
  	for(k=0;k<2;k++)
	{ 
 if(rp[k]==c.rr){
//printf ("\n%s %d %s %d", c.name, c.age, c.address, c.rr);
    printf("\n\tCUSTOMER NAME:\t%s",c.name);
    printf("\n\tCUSTOMER RR NO:\t%d",c.rr);
    printf("\n\tCUSTOMER AGE:\t%d",c.age);
    printf("\n\tCUSTOMER ADDRESS:\t%s\n",c.address);
    printf("\n\tCUSTOMER COST:\t%f\n",c.cost);
                 } 
	}
}
fclose ( fp ) ;

			printf("*************************************************************************************************************");	

			printf("\n*************************************************************************************************************");	
		/*	printf("\n DO you wnat to pay the bill now press 1.now 2.later\n");
			int n1;
			scanf("%d",&n1);
			if(n1==1)
			{
			   system("gcc billcheck.c");
				system("./a.out");
			system("clear");
			printf(" \n\n\n\n\t\tBILL PAID sucessfully !!!!\n");
			}	*/
                printf("\n\n\n\t\t\t\n\n\n\nSERVER EXITTING\n");
		exit(0);
               } 
           break;
	
 default: printf("PROGRAM NOT WORKING\n");
         break;
                }		
return 0;
}


		void wait1(int sm)
		{
		  
		  while(sm<=0);
		  sm--;
		}
		void signal1(int sm)
		{
		 sm++;
		}

  
