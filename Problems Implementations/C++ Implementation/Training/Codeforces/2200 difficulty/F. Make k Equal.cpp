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
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 
	int n,k;
 
	scanf("%d %d",&n,&k);
	std::vector<int> a(n+1);
	for (int i = 1; i <= n; i++){
        	scanf("%d",&a[i]);
    	}
    	
    	sort(a.begin() + 1, a.end());
    	
    	std::vector<ll> pref(n+1);
    	
    	for (int i = 1; i <= n; i++)pref[i] = pref[i - 1] + a[i];
    	
    	ll ans = 5e18;
    	
    	for (int i = 1; i <= n; i++){
    		ll r = upper_bound(a.begin() + 1, a .end(), a[i]) - a.begin();
       	 	
       	 	ll l = lower_bound(a .begin()+1, a .end(), a[i]) - a.begin() - 1;
        	
        	ll cnt = k - (r - l - 1);
	        
	        if (cnt <= 0)return !printf("0\n");
	        
	        ll wa1 = (a[i] - 1) * l - pref[l];
	        
	        ll wa2 = pref[n] - pref[r - 1] - (a[i] + 1) * (n - r + 1);
 
        	ll S = wa1 + min(cnt, l);
        	
        	cnt -= min(cnt, l);
	        
	        if (cnt > 0)S = S + wa2 + cnt;
	        
        	ans = min(ans, S);
       		
       		cnt = k - (r - l - 1);
        	
        	S = wa2 + min(cnt, n - r + 1);
        	
        	cnt -= min(cnt, n - r + 1);
	        
	        if (cnt > 0)S = S + wa1 + cnt;
	        
        	ans = min(ans, S);
    	}
    	printf("%lld\n",ans );
}