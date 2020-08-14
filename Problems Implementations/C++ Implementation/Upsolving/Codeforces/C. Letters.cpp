//                             ¯\_(ツ)_/¯   
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mma,ava,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define ll long long
 
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
int tc;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	int n,m;
	scanf("%d %d",&n,&m);
	std::vector<ll> pref(n+1);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		pref[i] = pref[i-1]+x;
	}
	while(m--){
		ll x;
		scanf("%lld",&x);
		auto it = lower_bound(pref.begin()+1,pref.end(),x);
		printf("%d %lld\n",it-pref.begin()+1,x- (it != pref.begin() ? *(--it) : 0));
	}
}
