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
int n,m;
std::vector<int> g[N];
std::vector<int> v;
int vis[N];
bool cycle;
void dfs(int u){
	vis[u] = 1;
	v.pb(u);
	for(auto v : g[u]){
		if(vis[v] == 2){
			cycle = true;
		}
		else if(vis[v] == 1) continue;
		else	dfs(v);
	}
	vis[u] = 2;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d %d",&n,&m);
 
	for(int i=0,a,b;i<m;i++)scanf("%d %d",&a,&b),g[a].pb(b),g[b].pb(a);
	int ans = 0;
	for(int i=1;i<=n;i++){
		v.clear();
		cycle = false;
		if(!vis[i]){
			dfs(i);
			if(cycle){
				bool yes = true;
				for(auto x : v)if(sz(g[x])!=2)yes = false;
				ans+=(int)yes;
			}
			
		}
	}
	printf("%d\n",ans );	
}