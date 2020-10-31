//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_bac(X/j)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9;
 
ll sum(int x){
	return (ll)x*(x+1)/2 %MOD;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
 
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
 
	ll ans = (((sum(a) * sum(b))%MOD) * sum(c))%MOD;	
	printf("%lld\n",ans );
}