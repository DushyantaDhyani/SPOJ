#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<long> A(N),B(N),C(N),D(N);
	vector<long> Result1,Result2;
	vector<long>::iterator it1,it2;
	int i=0;
	int j;
	int count=0;
	while(i<N){
		scanf("%ld %ld %ld %ld",&A[i],&B[i],&C[i],&D[i]);
		i++;
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Result1.push_back(-1*(A[i]+B[j]));
			Result2.push_back((C[i]+D[j]));
		}
	}
	sort(Result2.begin(),Result2.end());
	for(i=0;i<Result1.size();i++){
		it1=lower_bound(Result2.begin(),Result2.end(),(Result1[i]));
		it2=upper_bound(Result2.begin(),Result2.end(),(Result1[i]));
		count+=(it2-it1);
	}
	printf("%d\n",count);
	return 0;
}
