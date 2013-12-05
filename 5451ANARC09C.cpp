#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define MAX 1000000
using namespace std;
vector<int> Primes;
bool flag[MAX];
int precompute(){
	int i,j;
	int limit;
	i=2;
	limit=sqrt(MAX);
	flag[0]=flag[1]=1;
	while(i<=limit){
		if(flag[i]==0){
			Primes.push_back(i);
			j=i*i;
			while(j<MAX){
				flag[j]=1;
				j+=i;
			}
		}
		i++;
	}
	while(i<MAX){
		if(flag[i]==0){
			Primes.push_back(i);
		}
		i++;
	}
	return Primes.size();
}
int main(){
	long A,B;
	int i,j;
	int num;
	int X,D;
	int size;
	size=precompute();
	num=1;
	while(true){
		X=D=0;
		scanf("%ld %ld",&A,&B);
		if(A==0 && B==0){
			break;
		}
		int arr1[size],arr2[size];
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		i=0;
		while(i<size){
			while((A%Primes[i])==0){
				arr1[i]++;
				A=A/Primes[i];				
			}
			
			while((B%Primes[i])==0){
				arr2[i]++;
				B=B/Primes[i];				
			}
			i++;
		}
		i=0;
		while(i<size){
			if(arr1[i]!=0 || arr2[i]!=0){
				X++;
				D+=abs(arr1[i]-arr2[i]);
			}
			i++;
		}
		printf("%d. %d:%d\n",num,X,D);
		num++;
	}
	return 0;
}
