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
 
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9+7;
const ll INF = 2e18;
 
 
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
	return p1.second<p2.second;
}
void solve(int tc ){
	int n;
	scanf("%d",&n);
	std::vector<int> a(n);
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	std::vector<ll> dp(n);
	for(int i = 0;i<n;i++){
		if(i)dp[i]+=dp[i-1];
		dp[i]+=a[i];
	}
	ll mn = 1e18;
	ll ans = -1e18;
	for(int i = 0;i<n;i++){
		ans = max(ans,dp[i] - (mn<0? mn : 0));
		mn = min(mn,dp[i]);
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