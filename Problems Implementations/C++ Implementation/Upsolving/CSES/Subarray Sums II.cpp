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
 
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
	if(p1.first < p2.first)return true;
	if(p1.first > p2.first)return false;
	return p1.second>p2.second;
}
 
void solve(int tc ){
	
	int n,k;
 
	scanf("%d %d",&n,&k);
 
	map<ll,int>occ;
	occ[0] = 1;
	ll s = 0;
	ll ans = 0;
	for(int i = 0,x;i<n;i++){
			scanf("%d",&x);
			s+=x;
			ans+=occ[s-k]; 
			occ[s]++;
	}		
	printf("%lld\n",ans );
 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 	 
 	 int tc = 1;
 	//scanf("%d",&tc);
 	for(int i = 1;i<=tc;i++)
 		solve(i);
}