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
const int N=1e6+5,M=2e6+5,MOD=1e9+7,OO=1e9+7;
const ll INF = 2e18;
 
vector<vector<ll>>dp(N+1,vector<ll>(2));
 
void solve(int tc ){
    string a,b;
	cin>>b>>a;
	a = "#" + a;
	b = "#" + b;
	int n = sz(a) , m = sz(b);
	vector<vector<int>> dp(n,vector<int>(m,OO));
	dp[0][0] = 0;
	for(int i = 1;i < n;i++){
		for(int j = 0;j < m;j++){
			int not_equal = int(a[i] != b[j]);
			if(j)dp[i][j] = min(dp[i][j] , not_equal + dp[i-1][j-1]);
			dp[i][j] = min(dp[i][j] , 1 + dp[i-1][j]);
			if(j)dp[i][j] = min(dp[i][j],1 + dp[i][j-1]);
		}
	}
 
	cout<<dp[n-1][m-1]<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
    int tc = 1;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)solve(i);
}