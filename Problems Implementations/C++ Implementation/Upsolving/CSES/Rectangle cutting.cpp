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
   int n,m;
   
   scanf("%d %d",&n,&m);
 
   vector<vector<int>>dp(n+1,vector<int>(m+1,OO));
 
   for(int i =1;i<=n;i++){
	   for(int j=1;j<=m;j++){
		   if(i == j){
			   dp[i][j] = 0;
			   continue;
		   }
		   for(int k = 1;k < max(i,j);k++){
			   if(i>k)dp[i][j] = min(dp[i][j],1 + dp[i-k][j] + dp[k][j]);
               if(j>k)dp[i][j] = min(dp[i][j],1 + dp[i][j-k] + dp[i][k]);
		   }
	   }
   }
 
   printf("%d\n",dp[n][m]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
    int tc = 1;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)solve(i);
}