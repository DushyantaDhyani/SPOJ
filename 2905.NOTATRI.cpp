#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N,i,j;
	int count;
	while(true){
		count=0;
		scanf("%d",&N);
		if(N==0){
			break;
		}
		vector<long> Data(N),Result;
		i=0;
		while(i<N){
			scanf("%ld",&Data[i]);
			i++;
		}
		sort(Data.begin(),Data.end());
		for(i=0;i<N;i++){
			for(j=i+1;j<N;j++){
				count+=Data.end()-upper_bound(Data.begin()+j+1,Data.end(),(Data[i]+Data[j]));
			}
		}
		printf("%d\n",count);	
	}
	return 0;
}
