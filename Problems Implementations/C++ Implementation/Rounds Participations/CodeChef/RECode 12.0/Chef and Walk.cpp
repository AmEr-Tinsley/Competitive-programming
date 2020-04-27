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
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;

int powMOD(int a,int p){
	if (!p)
		return 1;
	if (p == 1)
		return a;
	int b = powMOD(a,p>>1);
	b = (ll)b * b % MOD;
	return (ll)b * powMOD(a,p&1) % MOD;
}
ll U(ll n){
	return 2 * n % MOD;
}

ll S(int p,int n){
	return ((n-p+1) * (U(n) + U(p) % MOD) % MOD ) * powMOD(2,MOD-2) % MOD;
}
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	if (n == 0){
		printf("%lld\n",S(0,k-1));
		return;
	}
	ll sf = -1 ;
	ll st = S(0,n + k / 2);
	if ( k % 2 == 0 )
		sf = ((U(n + k/2) - n) + MOD) % MOD;
	else
		sf = n;
	st = (st - sf + MOD) % MOD;
	
	printf("%lld\n",st);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	scanf("%d",&tc);

	while(tc--)solve();
}