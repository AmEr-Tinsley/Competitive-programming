//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
 	
 	int n;

 	scanf("%d",&n);
 	ll ans = 0;
 	for(int i = 0;i<n;i++){
 		int l,r;
 		scanf("%d %d",&l,&r);

 		ll sum = (ll)r*(r+1)/2 - (ll)l*(l-1)/2;
 		ans+=sum;
 	}
 	printf("%lld\n",ans );

	
}