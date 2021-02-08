#include<stdio.h>

int main(){
	int i,j,number1,number,remainder=0,dec;
	
	for(i=100;i<1000;i++){
		for(j=100;j<1000;j++){
			number=i*j;
			number1=i*j;
			while(number>0){
				dec=number%10;
				remainder=(10*remainder)+dec;
				number/=10;
			}
			if(number1==remainder){
				printf("%d\n",number1);
			}
		remainder=0;
		}
	}
		
	return 0;
}
