//
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstring>
// Input macros
#define s(n)  scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define maX(a,b) ((a) > (b) ? (a) : (b))
#define miN(a,b) ( (a) < (b) ? (a) : (b))
#define checkbit(n,b) ( (n >> b) & 1)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
using namespace std;
vector<int> Primes;
bool Flag[32000];
void preprocess(){
	Flag[0]=Flag[1]=true;
	int limit=sqrt(32000);
	int i=2,j;
	while(i<limit){
		if(!Flag[i]){
			Primes.push_back(i);
			j=i*i;
			while(j<32000){
				Flag[j]=true;
				j+=i;
			}	
		}
		i++;
	}
	while(i<32000){
		if(!Flag[i]){
			Primes.push_back(i);
		}
		i++;
	}
}
void fastLongRead(long *a){
	register char c=0;
	while(c<33){
		c=getchar_unlocked();
	}
	*a=0;
	while(c>33){
		*a=*a*10+(c-'0');
		c=getchar_unlocked();
	}
}
void getPrimes(long x,long y){
	int limit=sqrt(y);
	int i=0;
	long j;
	bool arr[y-x+1];
	fill(arr,0);
	while(i<Primes.size() && Primes[i]<=limit){
		if(x%Primes[i]==0){
			j=x;
		}
		else{
			j=(x/Primes[i])*Primes[i]+Primes[i];
		}
		if(j==Primes[i]){
			j+=Primes[i];
		}
		while(j<=y){
				arr[j-x]=true;
				j+=Primes[i];
		}
		i++;
	}
	i=0;
	if(x==1){
		i++;
	}
	while(i<(y-x+1)){
		if(!arr[i]){
			printf("%ld\n",(x+i));
		}
		i++;
	}
	printf("\n");
}
int main(){
	preprocess();
	long m,n;
	int T;
	scanf("%d",&T);
	while(T>0){
		fastLongRead(&m);fastLongRead(&n);
		getPrimes(m,n);
		T--;
	}
}
