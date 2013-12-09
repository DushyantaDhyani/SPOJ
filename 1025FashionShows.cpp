#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int T;
	int N;
	int i;
	long FinalVal;
	cin>>T;
	while(T>0){
		cin>>N;
		vector<int> men(N);
		vector<int> women(N);
		i=0;
		while(i<N){
			cin>>men[i];
			i++;
		}
		i=0;
		while(i<N){
			cin>>women[i];
			i++;
		}
		sort(men.begin(),men.end());
		sort(women.begin(),women.end());
		i=0;
		FinalVal=0;
		while(i<N){
			FinalVal+=men[i]*women[i];
			i++;
		}
		cout<<FinalVal<<endl;
		T--;
	}
}
