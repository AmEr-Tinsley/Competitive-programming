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
	file();
	ll s,p;
	scanf("%lld %lld",&s,&p);

	for(ll i = 1;i*i<=p;i++){
		if(p%i == 0 ){
			if(i + (p/i) == s){
				return !printf("Yes\n");
			}
		}
	}
	printf("No\n");
}