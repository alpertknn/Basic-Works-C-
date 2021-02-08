#include <stdio.h>
float sum(float *,int,int);

int main(){
	float arr[15]={1.2,3.6,7.8,-13.6,4.6,6,7.4,-8.6,-9.6,-10.4,12.4,13.6,-8,14.7};
	
	printf("The summation is:%f\n",sum(&arr,15,5));
	printf("The summation is:%f\n",sum(&arr[9],15,5));
	printf("The summation is:%f\n",sum(&arr[4],15,5));
	printf("The summation is:%f\n",sum(&arr[1],15,11));
	return 0;
}

float sum(float *arr ,int x,int c){
	int i;
	float sum=0;
	for(i=0;i<c;i++){
		sum+=*arr;
		arr++;
		
	}
			return sum;
	
	
}
