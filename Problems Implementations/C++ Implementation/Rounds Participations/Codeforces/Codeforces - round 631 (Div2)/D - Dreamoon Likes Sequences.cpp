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
const int X = 31;
void solve(){
	std::vector<ll> wa(52);
	ll ans = 0;
	int d,m;
	scanf("%d %d",&d,&m);
	ll curr = 1;
	for(int i = 0;i<(X-__builtin_clz(d));i++){
		wa[i]++;
		for(int j=0;j<i;j++)wa[i] = (wa[i]+wa[j])%m;
		wa[i] = ((1<<i) * wa[i]) %m; 
		ans+=wa[i];
		ans%=m;
		curr+=wa[i];
		curr%=m;
	}
	printf("%lld\n",(ans+curr*(d-(1<<(X-__builtin_clz(d)))+1)%m )%m);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d",&tc);
 
	while(tc--)solve();
}