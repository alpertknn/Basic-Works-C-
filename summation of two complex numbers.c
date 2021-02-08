#include<stdio.h>
int b=1;
struct  Complex{
	float real;
	float imag;
	
};
struct Complex get_numbers( struct Complex *ptr){
	struct Complex c1,c2;
	int i=0;
	
	for (i=0;i<=1;i++){
		printf("Enter the %d part:",b);
		b++;
	    scanf("%f%f",&ptr->real,&ptr->imag);
	    return *ptr;
	}
	
		
}
struct Complex addNumbers(struct Complex c1, struct Complex c2, struct Complex *result){
	int sum1=0;
	int sum2=0;
	result->imag=c1.imag+c2.imag;
	
	result->real=c1.real+c2.real;
	
	
}
void display(struct Complex *ptr){
     printf("The summation of 2 complex number is:%.2f+%.1fi",ptr->real,ptr->imag);
	
}

int main(){
	 struct Complex c1,c2;
	 struct Complex result,*ptr;
	 ptr=&c1;
	 c1=get_numbers(ptr);
	 ptr=&c2;
	 c2=get_numbers(ptr);
	 addNumbers(c1,c2,&result);
	 ptr=&result;
	 display(ptr);	
}
