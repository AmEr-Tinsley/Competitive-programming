#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
//using namespace  __gnu_pbds;
 
 //typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9+7;
const ll INF = 2e18;
 
 
void solve(int tc ){
	
	int n,x;
	scanf("%d %d",&n,&x);
	std::vector<int> a(n);
	for(auto &x:a)scanf("%d",&x);
	map<int,vector<pair<int,int>>>wa;
	for(int i = 0;i<n;i++){
		for(int j =i+1;j<n;j++){
			wa[a[i]+a[j]].push_back({i,j});
		}
	}
 
	for(int i = 0;i<n;i++){
		for(int j =i+1;j<n;j++){
			for(auto p : wa[x - a[i] -a[j]]){
				if(p.first != i && p.first!=j && p.second!=i && p.second!=j){
					std::vector<int> v = {i,j,p.first,p.second};
					sort(all(v));
					for(auto xx : v)printf("%d ",xx+1 );
					return;
				}
			}
		} 
	}
 
	printf("IMPOSSIBLE\n");
	
 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 	 
 	 int tc = 1;
 	//scanf("%d",&tc);
 	for(int i = 1;i<=tc;i++)
 		solve(i);
}