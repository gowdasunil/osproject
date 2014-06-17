#include<sys/shm.h>
#include<stdio.h>
void wait(int );
void signal(int );
int sig=1;
int main()
{
int  key;
const int size=4096;
int sid,*sm,*s,rr;
key=5678;
if((sid=shmget(key,size,IPC_CREAT|0777))<0)
{
 perror("shmget");
 exit(1);
}
if((sm=shmat(sid,NULL,0))==-1)
{
 perror("shmat");
exit(1);
}

 printf("child proces\nMY PID IS %d\n",getpid());
      //   printf("MY PARENT ID IS %d\n\n",getppid());
        //system("gcc client.c");       //  execlp("gcc ","gcc client.c","NULL");
        //      system("./a.out");
        //      printf("*%s\n",sm);
        //      for(s=sm;*s!=NULL;s++)
        //      putchar(*s);
               system("clear");
                printf("\n \t\t\t\t\t\tKEB E-BILLING SYSTEM \n\n\n\n");
                printf("\n\t\t\tCLIENT REQUEST (message from client process)\n");
                printf("\t\t\tENTER THE RR NO:\t");
                scanf("%d",&rr);
		wait(sig);
                s=sm;
                *s=(int )rr;
                s++;
                *s=NULL;
//              strcpy(s,rr);

                //*s++=NULL;
		do{
		printf("SERVER AS NOT READ YOUR REQUEST !!!!\n\n\t\tCLIENT PROCESS is exiting\n");
               }while(*s!=2);
			printf("\n\tYOOO YOOOO !!\n\tSERVER AS NOW  READ YOUR REQUEST !!!!\n\n\t\tserver is exiting\n");
 
		shmdt(sm);
                 printf("\n\t\t\tRequest sent to server wait for Response\n");
                 signal(sig);
		  sleep(3);
                exit(0);

/*for(s=shm;*s!=NULL;s++)
putchar(*s);
putchar("\n");
*shm='*';
exit(0);*/

return 0;


}


void wait(int s)
{
  if(s<=0)
  printf("\n\n\t \tSERVER IS BUSY !!\n");
   while(s<=0);
   s--;
}

void signal(int s)
{
  s++;
}

