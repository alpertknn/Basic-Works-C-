#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
struct Book
{
    char Book_name[50];
    char Book_author[15];
    int Book_id;
    char Book_subject [20];
    float Book_price;
};
struct node{
    struct Book info;
    struct node *next;
};
typedef struct node *NODEPTR;
struct Book books [5]={
"Aslan" ,"Alper Tekin", 341,"Hayvanlar",30.5,
"Einstein" ,"Salin Alperen", 546,"Insanlar",23.7,
"Cakal" ,"Ilker Kararmis", 122,"Bitkiler",10.3,
"Dalton" ,"Kadir Erguz", 323,"Cakallar ve Kurtlar",7.2,
"Bakkal" ,"Metin Polat", 224,"Bilim",50.12,
};
struct Book bookss [5]={
"Aslan" ,"Alper Tekin", 341,"Hayvanlar",30.5,
"Einstein" ,"Salin Alperen", 546,"Insanlar",23.7,
"Cakal" ,"Ilker Kararmis", 122,"Bitkiler",10.3,
"Dalton" ,"Kadir Erguz", 323,"Cakallar ve Kurtlar",7.2,
"Bakkal" ,"Metin Polat", 224,"Bilim",50.12,
};
NODEPTR createnode()
{  
    NODEPTR q;
    q = (NODEPTR) malloc(sizeof(struct node));
    return(q);
}


void reverse(NODEPTR *head) 
{ 
    NODEPTR prev  = NULL; 
    NODEPTR  save = *head; 
    NODEPTR neww; 
    while (save != NULL) 
    { 
        neww->info  = save->next->info;   
        save->next = prev;    
        prev = save; 
        save = neww; 
    } 
    *head=prev;
} 


void sortid(NODEPTR *head){  
    NODEPTR save,p,q;  
    
    save=*head;
    q=*head;
    p=NULL;  
    int x;    
    if(head == NULL){  
        return;  
    }  
    else{  
        while(save != NULL){  
            p=save->next;  
            while(p != NULL){  
	            if(save->info.Book_id > p->info.Book_id){  
	                x = save->info.Book_id;  
	                save->info.Book_id = p->info.Book_id;  
	                p->info.Book_id = x;  
	            }  
            	p = p->next;  
        	}  
       		save = save->next;  
    	}
    	
		while(q->next!=NULL){
		printf("%s %s %d %s %.2f\n",q->info.Book_name,q->info.Book_author,q->info.Book_id,q->info.Book_subject,q->info.Book_price);
		q=q->next;
		
	}      
    }
	  
}
void sortname(NODEPTR *head){ 
    NODEPTR save,p,q;  
    
    save=*head;
    q=*head;
    p=NULL;   
    char temp[50];    
      
     
        while(save != NULL){  
            p = save->next;  
            while(p != NULL){ 
            	int num;
				num=strcmp(save->info.Book_name, p->info.Book_name); 
            	if(num>0){ 
					strcpy(temp, save->info.Book_name); 
					strcpy(save->info.Book_name,p->info.Book_name);
					strcpy(p->info.Book_name, temp);
					
            	}
				
            	   p = p->next;  
            }  
            save = save->next; 
        	
    	}
    	q=*head;
		while(q->next!=NULL){
		q=q->next;
		printf("%s %s %d %s %.2f\n",q->info.Book_name,q->info.Book_author,q->info.Book_id,q->info.Book_subject,q->info.Book_price);
	    
	}	      
      
}

void insertn(NODEPTR *head){
    NODEPTR save,p,q;  
    
    q=*head;
    p=NULL;   
    int i,x;
    save=createnode();
    printf("\nWhere do you want to insert?: ");
    scanf("%d",&x);
    printf("New Id: ");
	scanf("%d",&save->info.Book_id);
	printf("New Name: ");
	scanf("%s",&save->info.Book_name);
	printf("New Author: ");
	scanf("%s",&save->info.Book_author);
	printf("New Subject: ");
	scanf("%s",&save->info.Book_subject);
	printf("New Price: ");
	scanf("%f",&save->info.Book_price);
    save->next=NULL;
    if(x==0){
        save->next=*head;
        *head=save;
    }
    else{
        for(i=0,p=*head;i<x-1;i++){
            p=p->next;
            if(p==NULL){
                printf("\nNot found !\n");
                return;
            }
        }
        save->next=p->next;
        p->next=save;
	}
}

void deletepos(NODEPTR *head){    
    int i,y;
    NODEPTR p,q,save;
    q=*head;
    if(head==NULL){
        printf("\nList is empty !\n");
        exit(0);
    }
    else{
        printf("\nEnter the position for deleting: ");
        scanf("%d",&y);
        if(y==0){
            p=q;
            q=q->next ;
            printf("\n Deleted Element:\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            
            printf("\nBook Id:%d\nBook Name:%s\nBook Author:%s\nBook Subject:%s\nBook Price:%f\n",p->info.Book_id,p->info.Book_name,p->info.Book_author,p->info.Book_subject,p->info.Book_price);
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            free(p);
        }
        else{
            p=q;
            for(i=0;i<y;i++){
                save=p;
            	p=p->next ;
                if(p==NULL){
                	printf("\nIndex is not found !\n");
                    return;
                }
            }
            save->next =p->next ;
            printf("\nDeleted Element \n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\nBook Id:%d\nBook Name:%s\nBook Author:%s\nBook Subject:%s\nBook Price:%.2f\n",p->info.Book_id,p->info.Book_name,p->info.Book_author,p->info.Book_subject,p->info.Book_price);
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			free(p);
        }
    }
}

int main(){                                 /*--------------------------MAINNNNNNNNNNN--------------------*/
	int i;
	char choice;
	NODEPTR p,q,save,head,temp,newlist,newlisthead;
	p=createnode();
	p->next=NULL;
	head=p;
	save=head;
	
	
	for(i=0;i<5;i++){
		
		
		save->info=books[i];
		save->next=createnode();
		save=save->next;
		save->next=NULL;
	
	}
	save=head;

	while(save->next!=NULL){
		printf("%s %s %d %s %.2f\n",save->info.Book_name,save->info.Book_author,save->info.Book_id,save->info.Book_subject,save->info.Book_price);
		save=save->next;
		
	}
	do{
    
	printf("----------------------------------------------------------------------------------------------\n");
	printf("Enter a for Sorting Book_id \n");
	printf("Enter b for Sorting Book_name'\n");
	printf("Enter c for Append  at the beginning \n");
	printf("Enter d for Append  as a second node \n");
	printf("Enter e for Delete the save element \n");
	printf("Enter f for Delete the nth element \n");
	printf("Enter g for Insert an element before the nth element \n");
	printf("Enter h for Free all nodes in a list.\n");
	printf("Enter i for Concatenate two lists.\n");
	printf("Enter j for Reverse a list, so that the last element becomes the first, and so on.\n");
	printf("Enter k for Combine two ordered lists into a single ordered list.\n");
	printf("Enter l for Form a list containing the intersection of the elements of two lists\n");
	printf("Enter m for Form a list containing the union of the elements of two lists.\n");
	printf("----------------------------------------------------------------------------------------------\n");
	printf("Enter your choice(!!E for Exit!!):");
	scanf("%s",&choice);
	switch(choice){
		case 'a':
			sortid(&head);
			break;
		case 'b':
			sortname(&head);  
			break;
		case 'c':
			save=head;
			save=createnode();
			printf("Enter the Book ID: ");
			scanf("%d",&save->info.Book_id);
			printf("Enter the Book Name: ");
			scanf("%s",&save->info.Book_name);
			printf("Enter the Book Author: ");
			scanf("%s",&save->info.Book_author);
			printf("Enter the Book Subject: ");
			scanf("%s",&save->info.Book_subject);
			printf("Enter the Book Price: ");
			scanf("%f",&save->info.Book_price);
			save->next =NULL;
			if(head==NULL){
			head=save;
			}
			else
			{
			save->next=head;
			head=save;
			}
			
			break;
		case 'd':   
			p=head;
			q=head;
			temp=head;
			p=head->next;
			save=head;
			temp=createnode();
			printf("New Book Id: ");
			scanf("%d",&temp->info.Book_id);
			printf("New Book Name: ");
			scanf("%s",&temp->info.Book_name);
			printf("New Book Author: ");
			scanf("%s",&temp->info.Book_author);
			printf("New Book Subject: ");
			scanf("%s",&temp->info.Book_subject);
			printf("New Book Price: ");
			scanf("%f",&temp->info.Book_price);
			temp->next=p;
			head->next=temp;
			
			while(save->next!=NULL){
		        printf("%s %s %d %s %.2f\n",save->info.Book_name,save->info.Book_author,save->info.Book_id,save->info.Book_subject,save->info.Book_price);
		        save=save->next;
				}
				break;
			case 'e':
			head=head->next;
			while(head->next!=NULL){
		        printf("%s %s %d %s %.2f\n",head->info.Book_name,head->info.Book_author,head->info.Book_id,head->info.Book_subject,head->info.Book_price);
		        head=head->next;
				}
				break;
			case 'f':
			deletepos(&head);
			break;
			case 'g':
			insertn(&head);
			while(head->next!=NULL){
			printf("\n------------>%s %s %d %s %.2f\n",head->info.Book_name,head->info.Book_author,head->info.Book_id,head->info.Book_subject,head->info.Book_price);
			head=head->next;
			}
			break;
			case 'h':
			free(head);
			head=NULL;
			if(head==NULL){
				printf("Empty!!");
			}
			 
			
			break;
		case 'i':                                                              /*Mistake*/
		    newlist=createnode();
		    newlisthead=newlist;
		    save=newlisthead;
		    newlist->next=NULL;
		    for(i=0;i<5;i++){
			save->info=books[i];
			save =createnode();
			save=newlist->next;
			save->next=NULL;
			newlist=newlist->next;
			}
	
			
			
			save=newlisthead;
			p=head;
			while(p->next=NULL){
				p=p->next;
			}
			p=newlist;
			
			
				
				newlist->next=save;
				p=head;
				
			
			
			while(p->next!=NULL){
		        printf("%s %s %d %s %.2f\n",p->info.Book_name,p->info.Book_author,p->info.Book_id,p->info.Book_subject,p->info.Book_price);
		        p=p->next;
				}
			
			
			break;
		case 'j':                                                        /*Mistake*/
			save=head;
			p=head;
			while(p->next!=NULL){
		        p=p->next;
				}
			
			
			break;

		default:
			printf("\nEnter again!!");
			break;
			
			
		}
   }while(choice!='E');
       return 0;
}

