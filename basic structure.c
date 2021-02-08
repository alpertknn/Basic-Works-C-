#include <stdio.h>
struct student
{
    char name[50];
    int age;
};
void display(struct student);
struct student getInformation();
int main()
{
    struct student s;
    s = getInformation();
    display(s);
    
    return 0;
}
struct student getInformation() 
{
  struct student s;
  printf("Enter name: ");
  scanf ("%s",&s.name);
  printf("Enter age: ");
  scanf("%d", &s.age);
  
  return s;
}	
void display(struct student s){
	
	printf("The Name is : %s",s.name);
    printf("\nThe age is : %d", s.age);
}
