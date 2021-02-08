#include<stdio.h>
#include<stdlib.h>

int a;


struct node{
	int number;
	struct node *next;
	
	
};
typedef struct node *NODEPTR;



NODEPTR createnode(){
	NODEPTR q;
	q=(NODEPTR)malloc(sizeof(struct node));
	return q;
	
	
}


void primenumbers(NODEPTR *head){
	NODEPTR p,q;
	p=*head;
	int i,c;
	c=0; 
	do{
		for(i=1;i<=p->number;i++){
			if(p->number%i==0){
				c++;		
			}		
		
		}
		
		if(c==2){
			printf("\n%d ",p->number);
		}
		
		
		p=p->next;
		c=0;
	}while(p->next!=NULL);


}

float average(NODEPTR *head){
	
	NODEPTR p;
	p=*head;
	float avg,tot=0;
	int i;
	for( i=0;i<a;i++){
		tot+=p->number;
		p=p->next;
		
	}
	avg=tot/a;
	return avg;

}

int main(){
	
	srand(time(NULL));
	NODEPTR p,head,save;
	p=createnode();
	p->next=NULL;
	save=head=p;
	head->number=rand()%20+1;
	
	printf("How many nodes do you want to create?:");
	scanf("%d",&a);
	int i;
	
	for(i=0;i<a;i++){
		save=createnode();
		save->number=rand()%20+1;
	    p->next=save;
	    save->next=NULL;
	    p=p->next;
	    
	}
	p=head;
	for(i=0;i<a;i++){
		printf("\n%d",p->number);
		p=p->next;
	}
	printf("\nThe average of the numbers is:%.2f",average(&head));
	printf("\n-------Prime Numbers Are:-------");
	primenumbers(&head);

	
	return 0;
}

