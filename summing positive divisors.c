#include<stdio.h>
int main(){
	int i,j,r=0;
	for(i=1000;i<10000;i++){
		for(j=1;j<i;j++){
			if(i%j==0)
			{
				r+=j;
			}
	
		}
		if(r==i)
			{
				printf("%d\n",i);
			}
		r=0;
	}
	
	return 0;
}
