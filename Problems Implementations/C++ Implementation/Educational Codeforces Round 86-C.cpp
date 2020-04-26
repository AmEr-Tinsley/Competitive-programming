#include <bits/stdc++.h>
 
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
 
ll pref[100000];
void solve(){
	int a,b,q;
	memset(pref,0,sizeof(pref));
	scanf("%d %d %d",&a,&b,&q);
	int mx = a * b;
	for(int i = 1 ; i <= mx ; i++){
		pref[i] = pref[i-1];
		if ((i % b % a) !=(i % a % b)){
			pref[i]++;
		}
	}
	while(q--){
		ll l,r;
		scanf("%lld %lld",&l,&r);
		l--;
		ll d   = r / mx;
		ll d2  = l / mx;
		ll ans = pref[mx] * d  + pref[r%mx] - pref[mx] * d2 - pref[l%mx];
		printf("%lld ",ans);
	}
	printf("\n");
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d",&tc);
 
	while(tc--){
		solve();
	}
}