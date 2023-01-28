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
    int n;
	cin>>n;

    vector<string>a(n);
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i =0;i<n;i++)cin>>a[i];
    dp[0][0] = int(a[0][0] != '*');
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == '*')continue;
            if(j && a[i][j-1] != '*')dp[i][j] += dp[i][j-1];
            if(i && a[i-1][j] != '*')dp[i][j] += dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }

    cout<<dp[n-1][n-1]<<endl;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

    int tc = 1;
 	//scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)solve(i);
}