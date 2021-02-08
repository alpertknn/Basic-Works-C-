#include<stdio.h>
int number,i,r=1,dec,number,result;
int find(int number){
	
	for(i=number;i>0;i/=10){
		dec=i%10;
		r*=dec;
	}
	
	return r;
}



int main(){
	printf("Enter a number:");
	scanf("%d",&number);
	printf("%d\n",number);
	while(number>10)
	{
		number=find(number);
		printf("%d\n"     ,number);
		r=1;
	}
	return 0;
	
}
