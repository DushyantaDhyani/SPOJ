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
void fastLongLongRead(long long *a){
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
long long getNum(string str){
    long long num=0;
    forall(i,0,sz(str)){
        num=num*10+(str[i]-48);
    }
    return num;
}
long long fixValue(string str,long long mod){
   if(sz(str)<=9) {
        return (getNum(str)%mod);
   }
   else{
        return ((fixValue(str.substr(0,sz(str)-9),mod)*(1000000000%mod))%mod+getNum(str.substr(sz(str)-9)));
   }
}
int main(){
	int T;
    long long N;
    long long SUM;
    string str;
    scanf("%d",&T);
    while(T>0){
        SUM=0;
        fastLongLongRead(&N);
        forall(i,0,N) {
            cin>>str;
            SUM+=fixValue(str,N);
        }
        if((SUM%N)==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        T--;
    }
    return 0;
}
