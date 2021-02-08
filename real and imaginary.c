#include<stdio.h>
#include<math.h>


int main(){
	int i,j;
	double lside,rside;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			lside=1+pow(2,i)+pow(2,2*i)*2;
			rside=j*j;
			if(lside==rside){
				printf("(%d,%d)\n",i,j);
			}
		}
		
	}
	for(i=0;i>-10;i--){
		for(j=0;j>-10;j--){
			lside=1+pow(2,i)+pow(2,2*i)*2;
			rside=j*j;
			if(lside==rside){
				printf("(%d,%d)\n",i,j);
			}
		}
		
	}

	return 0;
}
