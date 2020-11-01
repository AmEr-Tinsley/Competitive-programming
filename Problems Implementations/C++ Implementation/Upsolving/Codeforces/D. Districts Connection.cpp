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
int root[5001];
int find(int u){
	if(root[u] == u)return u;
	return find(root[u]);
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)root[i] = i;
	std::vector<int> a(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}

	std::vector<pair<int,int>> edges;
	std::vector<pair<int,int>> ans;
	for(int i = 0 ;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(a[i]!=a[j]){
				edges.pb({i,j});
			}
		}
	}

	for(auto p : edges){
		int x = p.first , y = p.second;
		int p1 = find(x) , p2 = find(y);
		if(p1 == p2)continue;
		ans.pb({x+1,y+1});
		root[p1] = p2;
		if(sz(ans) == n-1)break;
	}
	if(sz(ans)!= n-1){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(auto p : ans){
			printf("%d %d\n",p.first,p.second);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 
	scanf("%d",&tc);

	while(tc--)solve();
}