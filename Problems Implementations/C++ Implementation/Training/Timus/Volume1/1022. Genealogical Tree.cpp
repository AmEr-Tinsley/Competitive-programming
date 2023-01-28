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
    	freopen("test.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	int n;

	scanf("%d",&n);
	vector<vector<int>>g(n+1);
	std::vector<int> in(n+1);
	for(int i =1;i<=n;i++){
		int x;
		while(scanf("%d",&x) && x){
			in[x]++;
			g[i].pb(x);
		}
	}
	std::vector<int> ready;
	for(int i=1;i<=n;i++)if(in[i]==0)ready.pb(i);

	while(sz(ready)){
		int u = ready.back();
		printf("%d ",u);
		ready.pop_back();
		for(auto v : g[u]){
			in[v]--;
			if(in[v]==0)ready.pb(v);
		}
	}
}