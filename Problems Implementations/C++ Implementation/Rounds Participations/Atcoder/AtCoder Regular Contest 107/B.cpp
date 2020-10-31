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
int n;
ll how_many(int x){
	if(x <= 0 || x>2*n)return 0;
	ll ret = x > n ? n-(x-n-1) : x-1;
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

	int k;
	scanf("%d %d",&n,&k);
	ll ans = 0;
	for(int i = 2;i <= 2*n;i++){
		int needed = i - k;
		ans += how_many(i) * how_many(needed);
	}

	printf("%lld\n",ans);
}

