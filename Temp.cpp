#include<iostream>
#include<cstdio>
#include<cmath>
bool isPrime(int value){
	int i=2;
	int limit=sqrt(value);
	while(i<=limit){
		if((value%i)==0){
			return false;
		}
		i++;
	}
	return true;
}
int main(){
	int T;
	int N;
	int temp;
	int x,y,i,j,count;
	int limit1,limit2;
	scanf("%d",&T);
	while(T>0){
		count=0;
		scanf("%d",&N);
		i=1;
		limit1=sqrt(N);
		limit2=sqrt(limit1);
		while(i<=limit1){
			j=1;
			while(j<=limit2){
				temp=pow(i,2)+pow(j,4);
				if(temp>N){
					break;
				}
				else if(isPrime(temp)){
					count++;
				}
				j++;
			}
			i++;
		}
		printf("%d\n",count);
		T--;
	}
	return 0;
}
