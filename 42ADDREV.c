#include<stdio.h>
unsigned long long int revNum(unsigned long long int num){
	unsigned long long int reverse=0;
	while(num>0){
		reverse=reverse*10+(num%10);
		num/=10;
	}
	return reverse;
}
int main(){
	int T;
	unsigned long long int x,y;
	scanf("%d",&T);
	while(T>0){
		scanf("%llu %llu",&x,&y);
		x=revNum(x);
		y=revNum(y);
		x+=y;
		printf("%llu\n",revNum(x));
		T--;
	}
	return 0;
}
