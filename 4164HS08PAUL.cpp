#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAX 10000000
using namespace std;
vector<int> Primes;
bool flag[MAX];
int precompute(){
	int i,j;
	int limit;
	i=2;
	limit=sqrt(MAX);
	flag[0]=flag[1]=true;
	while(i<=limit){
		if(!flag[i]){
			Primes.push_back(i);
			j=i*i;
			while(j<MAX){
				flag[j]=true;
				j+=i;
			}
		}
		i++;
	}
	while(i<MAX){
		if(!flag[i]){
			Primes.push_back(i);
		}
		i++;
	}
	return Primes.size();
}
int main(){
	int size=precompute();
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
				else if(binary_search(Primes.begin(),Primes.end(),temp)){
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
