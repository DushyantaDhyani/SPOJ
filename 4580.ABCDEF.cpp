#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<int> Data(N);
	vector<int> Result1,Result2;
	vector<int>::iterator it1,it2;
	int i=0;
	int count=0;
	int j,k,l;
	int a,b,c,d,e,f;
	while(i<N){
		scanf("%d",&Data[i]);
		i++;
	}
	//sort(Data.begin(),Data.end());
	for(i=0;i<N;i++){
		a=Data[i];
		for(j=0;j<N;j++){
			b=Data[j];
			for(k=0;k<N;k++){
				c=Data[k];
				Result1.push_back((a*b+c));
			}
		}
	}
	sort(Result1.begin(),Result1.end());
	for(i=0;i<N;i++){
		d=Data[i];
		if(d!=0){
			for(j=0;j<N;j++){
				e=Data[j];
				for(k=0;k<N;k++){
					f=Data[k];
					Result2.push_back(d*(e+f));	
				}
			}
		}
	}
	sort(Result2.begin(),Result2.end());
	for(i=0;i<Result1.size();i++){
		it1=lower_bound(Result2.begin(),Result2.end(),Result1[i]);
		it2=upper_bound(Result2.begin(),Result2.end(),Result1[i]);
		count+=(it2-it1);
	}
	printf("%d\n",count);
	return 0;
}
