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
void fastIntRead(int *a){
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
int main(){
	int N,T,k=1;
	while(true){
		fastIntRead(&N);
		if(N==0){
			break;
		}
		vector< vector<int> > Data(N);
		vector<long long> Total(N);
		long long sum,psum;
		sum=psum=0;
		forall(i,0,N){
			Data[i].resize(N);
			Total[i]=0;
			forall(j,0,N){
				fastIntRead(&Data[i][j]);
				psum+=Data[i][j];
				Total[i]-=Data[i][j];
			}
		}
		forall(i,0,N){
			forall(j,0,N){
				Total[i]+=Data[j][i];
			}
		}
		forall(i,0,N){
			if(Total[i]>0){
				sum+=Total[i];
			}
		}
		printf("%d. %lld %lld\n",k,psum,sum);
		k++;
	}
	return 0;
}
