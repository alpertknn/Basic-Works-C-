#include<stdio.h>

int main(){
	int i,max,min,tot=0;
	float avg;
	int arr[]={15,24,57,89,41,25,12,90,85};
	max=arr[0];
	min=arr[0];
	
	for(i=0;i<9;i++){
		if(max<arr[i]){
			max=arr[i];
		}
		if(min>arr[i]){
			min=arr[i];
		}
		tot+=arr[i];
	
	}
	avg=tot/9;
	printf("Max:%d\n",max);
	printf("Min:%d\n",min);
	printf("Avg:%.2f",avg);
	
	
	return 0;
}
