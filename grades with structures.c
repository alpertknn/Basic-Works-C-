#include <stdio.h>

struct student{
	char name[30];
	char surname[30];
	int id;	
};
struct courses{
	int course_id;
	char course_name[30] ;
	float midterm;
	float final;
};
int main(){
	struct student std[10];
	struct courses crs[10];
	int i,a;
	float avg=0,avgf=0;
	printf("How many students will you enter?:");
	scanf("%d",&a);
	printf("\n");
	for(i=0;i<a;i++){
	printf("Enter the id for the student: ");
	scanf("%d",&std[i].id);
	printf("Enter the name for the student: ");
	scanf("%s",std[i].name);
	printf("Enter the surname for the student: ");
	scanf("%s",std[i].surname);	
	printf("\n");
	printf("Enter the id for the course: ");
	scanf("%d",&crs[i].course_id);
	printf("Enter the name for the course: ");
	scanf("%s",crs[i].course_name);
	printf("Enter the midterm for the course: ");
	scanf("%f",&crs[i].midterm);
	printf("Enter the final for the course: ");
	scanf("%f",&crs[i].final);
	printf("\n");
	}
	printf("\n||Student ID ||Student Name ||Student Surname ||Course Name	||Midterm ||Final ||\n");
	printf("------------------------------------------------------------------------------------");
    for(i = 0; i < a; i++)
    {
        printf("\n||%-11d||%-13s||%-16s||%-16s||%-8.2f||%-6.2f||\n",std[i].id,std[i].name,std[i].surname,crs[i].course_name,crs[i].midterm,crs[i].final);
     
    }
    for(i=0;i<a;i++){
    	avg+=crs[i].midterm;
    	avgf+=crs[i].final;
	}
	printf("\nClass avarage of midterm: %3.2f",avg/a);
	printf("\nClass avarage of final: %3.2f",avgf/a);
	
	return 0;
}
