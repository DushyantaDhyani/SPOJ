#include<stdio.h>
int main(){
	int T,N,limit,i,j,temp;
	int arr[1000];
	scanf("%d",&T);
	while(T>0){
		scanf("%d",&N);
		limit=0;
		arr[0]=1;
		i=2;
		while(i<=N){
			j=0;
			temp=0;
			while(j<=limit){
				temp=arr[j]*i+temp;
				arr[j]=temp%10;
				temp=temp/10;
				j++;
			}
			while(temp>0){
				arr[++limit]=temp%10;
				temp=temp/10;
			}
			i++;
			}
		j=limit;
		while(j>=0){
			printf("%d",arr[j]);
			j--;
		}
		printf("\n");
		T--;
	}
	return 0;
}
