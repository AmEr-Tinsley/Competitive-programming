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
    	//freopen("out.txt","w",stdout);
	#endif
}
int tc;
const int N=3e5+5,M=2e6+5,MOD=1e9+7,OO=1e9+7;
const ll INF = 2e18;
 
 
 
void solve(int tc ){
	//cout<<"Case #"<<tc<<": ";
 
	int n,s;
	scanf("%d %d",&n,&s);
	std::vector<int> a(n);
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
 
	std::vector<int> dp(s+1,1e9);
	dp[0] = 0;
	for(int i = 1;i<=s;i++){
		for(int j=0;j<n;j++){
			if(i>=a[j])dp[i] = min(dp[i],dp[i-a[j]]+1);
		}
	}
	if(dp[s]<1e9)printf("%d\n",dp[s] );
	else	printf("-1\n");
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 
 	int tc = 1;
 	//cin>>tc;
 	for(int i = 1;i<=tc;i++)
 		solve(i);
}