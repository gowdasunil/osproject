#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include"sys/types.h"
#include"wait.h"
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>

void main()
{
   pid_t pid;
   FILE *fp;
   int key=5678;
   int *sm,*s,rr,rp;
   const int size=4096;
   int sid,n,i;

  if((sid=shmget(key,size,IPC_CREAT|0777))<0)
   {
  	perror("shmat");
	exit(0);
    }

	if((sm=shmat(sid,NULL,0))==-1)
	{
		perror("shmat");
		exit(1);
	}



//fpr semaphore

/*int  key1;
const int size1=100;
int sid1,*sm1,*s1,rr1;
key1=1111;
if((sid1=shmget(key1,size1,IPC_CREAT|0777))<0)
{
 perror("shmget");
 exit(1);
}
if((sm1=shmat(sid1,NULL,0))==-1)
{
 perror("shmat");
 exit(1);
}

*/
//for semaphore
int  key2;
int k1=0;
const int size2=100;
int sid2,*sm2,*s2,rr2;
key2=8999;
if((sid2=shmget(key2,size2,IPC_CREAT|0777))<0)
{
 perror("shmget");
 exit(1);
}
if((sm2=shmat(sid2,NULL,0))==-1)
{
 perror("shmat");
exit(1);
}





//	pid=fork();
//	if(pid<0)
//	{
//		fprintf(stderr,"\n\t\t\tSERVER PROCESS NOT CREATED!!\n",NULL);
//		exit(-1);
//	}
//	else if(pid==0)
//	{
         printf("\nMESSAGE FROM SERVER PROCESS  MY ID IS:%d\n\n",getpid());
        //      execlp("gcc","gcc","server.c","NULL");

        //      system("gcc server.c");

        //      system("./a.out");
        //      wait(NULL);
          //            printf("\nPARENT EXITTING\n");/		
		
		//	*sm2=(int )k1;
 
			while(*sm2==1)	
			{
			*sm2=(int )0;


		s=sm;
           //    while(*s!=NULL){
                rp=*s;
               // s++; //}
		
                        printf("*************************************************************************************************************");
                        printf("\n*************************************************************************************************************");

                        printf("\n\t\t\tCLIENT REQUESTED BILL FOR RR NO ----->%d\n\n",rp);
		*s=(int )2;	
	
            

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
{   if(rp==c.rr){
//printf ("\n%s %d %s %d", c.name, c.age, c.address, c.rr);
    printf("\n\tCUSTOMER NAME:\t%s",c.name);
    printf("\n\tCUSTOMER RR NO:\t%d",c.rr);
    printf("\n\tCUSTOMER AGE:\t%d",c.age);
    printf("\n\tCUSTOMER ADDRESS:\t%s\n",c.address);
    printf("\n\tCUSTOMER COST:\t%f\n",c.cost);
                 }
}
fclose ( fp ) ;
 printf("*************************************************************************************************************");

                        printf("\n*************************************************************************************************************");
	


			sleep(5);
                        printf("\n DO you wnat to pay the bill now press 1.now 2.later\n");
                        int n1,n2;
                        scanf("%d %d",&n1,&n2);
                        if(n2==1)
                        {
                           system("gcc billcheck.c");
                                system("./a.out");
                        system("clear");
                        }
		
	}
			
		  shmdt(sm);
                  shmctl(sid,IPC_RMID,NULL);

			shmdt(sm2);
			shmctl(sid2,IPC_RMID,NULL);
                printf("\n\n\n\t\t\t\n\n\n\nSERVER EXITTING\n");
                exit(0);

           //    }
}
