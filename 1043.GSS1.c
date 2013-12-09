#include<stdio.h>
int arr[50000];
long segtree[300000];
long max(long num1,long num2){
	return num1>num2?num1:num2;
}
void setTree(long node,int begin ,int end){
	if(begin==end){
		segtree[node-1]=(long)arr[begin];
	}
	else{
		setTree(2*node,begin,(begin+end)/2);
		setTree(2*node+1,(begin+end)/2,end);
		segtree[node-1]=segtree[2*node-1]+segtree[2*node];
	}
}
long getMax(int node,int begin,int end,int i,int j){
	long sum1,sum2;
	if(i>end || j<begin){
		return 0;
	}
	if(begin>=i && end<=j){
		return segtree[node-1];
	}
	sum1=getMax(2*node,begin,(begin+end)/2,i,j);
	sum2=getMax(2*node+1,(begin+end)/2+1,end,i,j);
	return max(sum1,sum2);
}
int main(){
	int N,M,x,y;
	scanf("%d",&N);
	int i=0;
	while(i<N){
		scanf("%d",&arr[i]);
		i++;
	}
	setTree(1,0,N-1);
	scanf("%d",&M);
	while(M>0){
		scanf("%d %d",&x,&y);
		printf("%d\n",getMax(1,0,(N-1),x-1,y-1));
		M--;
	}
	return 0;
}
