#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,r=0,number;
	int output[10];
	printf("Enter a number:");
	scanf("%d",&number); 
	
	for(i=0;number>0;i++){
		output[i]=number%2;
		number/=2;
			
	}

	for(i=i-1;i>=0;i--){
		printf("%d",output[i]);
	}
	
	
	
	return 0;
}

