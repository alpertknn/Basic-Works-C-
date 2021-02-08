#include<stdio.h>               
#include<stdlib.h>               
#define TRUE 1
#define FALSE 1
#define SIZE 10



struct teacher
{   char F_name[12];
    char L_name[12];
    int TC;
    char address[20];
    char email[30];
    char mobile[12];
    char department[2];
};

struct queue
{   struct teacher std_info[10];
    int front,rear;
};
struct teacher HKU [10]={
"Ahmet" ,"Osman", 12005310,"Gaziantep","Ahmet@gmail.com","05531001020","CE",
"Sevgi" ,"Mert", 12005311,"Konya"," Sevgi@gmail.com","05531141990","E",                                
"Osman", "Kemal", 12005312,"Istanbul"," Osman@gmail.com","05531331023","CE",
"Mert", "Osman", 12005313, "Antalya"," Mert@gmail.com", "05531041424","CE",
"Ayse","Omer", 12005314,"Ankara"," Ayse@gmail.com","05531087412","E",
"Kemal", "ali", 12005315, "Izmir"," Kemal@gmail.com","05535471028","CE",
"Lale", "Can", 12005316,"Trabzon"," Lale@gmail.com","05534712036","E",
"Sefer", "Mert", 12005317, "Mardin"," Sefer@gmail.com","05531078621","CE",
"Meral","Jemal", 12005318,"Bursa"," Meral@gmail.com","05531003578","E",
"Demet", "Kemal", 12005319,"Ankara"," Demet@gmail.com","05531841220","E"
	};

void enqueue(struct queue *qs,struct teacher tch)
{
	if(qs->front==0&& qs->rear==SIZE-1||qs->front==qs->rear+1)
	{
		printf("Queue is full!");
	}
	if(qs->front==-1)
	{
		qs->front=0;
		qs->rear=0;
   }
   else{
		if(qs->rear==SIZE-1)
		{
			qs->rear=0;
		}
		else{
			qs->rear=qs->rear+1;
			}
	}
		qs->std_info[qs->rear]=tch;
	
}

struct teacher dequeue(struct queue *qs)
{
	struct teacher newt;
	
	
	if(qs->front==-1)
	{
		printf("\nQueue is empty!");
		exit(1);
		
	}
	newt=qs->std_info[qs->front];
	if(qs->front==qs->rear)
	{
		qs->front=-1;
		qs->rear=-1;
	}
	
	
	else{
		if(qs->front==SIZE-1
		){
			qs->front=0;
			}
		else{
			qs->front=qs->front+1;
			}
		}
	return (newt);
	
	
}
int main(){
	int i=0;
	struct queue q,q1,q2;
	struct teacher new1;
	q.front=-1;
	q.rear=-1;
	q1.front=-1;
	q1.rear=-1;
	q2.front=-1;
	q2.rear=-1;
	char operation;
	int ce=0;
	int e=0;
	
	char c;
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("\nEnter 1 for creating queue");
		printf("\nEnter 2 for Separating informations");
		printf("\nEnter 3 display the contents");
		printf("\nEnter 4 for Clear");
		printf("\nEnter 5 for Exit ");
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    do
	{
		printf("\nEnter your Operation:");
		scanf("\n%c",&operation);
		switch(operation)
		{
		case '1':
			 for(i=0;i<SIZE;i++)
			{
    	        enqueue(&q,HKU[i]);
			}
			break;
		case '2':
			if(q1.rear<4&&q2.rear<4)
			{
				for(i=0;i<SIZE;i++)
			{
				c=HKU[i].department[0];
				if(c=='C')
				{
				enqueue(&q1,HKU[i]);
				ce++;
				
				}
                else
				{
				enqueue(&q2,HKU[i]);
				e++;
				}
			}
				
			}
			else
			{
				printf("\nQueue is Fulll!!");
			}
			break;	
		case '3':
			for(i=0;i<=q1.rear;i++)
			{
			new1=dequeue(&q1);
	    	printf("\n%s  %s  %d  %s  %s  %s  %s",new1.F_name,new1.L_name,new1.TC,new1.address,new1.email,new1.mobile,new1.department);
			}
			printf("\n");	
			printf("------------------------------------------------------------------------");
			for(i=0;i<=q2.rear;i++)
			{
				new1=dequeue(&q2);
				printf("\n%s  %s  %d  %s  %s  %s  %s",new1.F_name,new1.L_name,new1.TC,new1.address,new1.email,new1.mobile,new1.department);
			}
			break; 
		case '4':
			q.front=-1;
	        q.rear=-1;
	        q1.front=-1;
	        q1.rear=-1;
	        q2.front=-1;
	        q2.rear=-1;
			printf("\nContents Deleted!!");
			break;
		case '5':
			printf("\nClosing....");
			break;
		default:
			printf("Wrong Choice!!\n");
		}
    }while(operation!='5');
	return 0;
}







