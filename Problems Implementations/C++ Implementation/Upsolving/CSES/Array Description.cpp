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
    int n,m;

    scanf("%d %d",&n,&m);

    vector<vector<ll>>dp(n,vector<ll>(m+2));

    int x;
    scanf("%d",&x);

    if(x)dp[0][x] = 1;
    else {
        for(int i =1;i<=m;i++)dp[0][i] = 1;
    }

    for(int i =1;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x){
            dp[i][x] = (dp[i-1][x] + dp[i-1][x+1] + dp[i-1][x-1])%MOD;
        }
        else{
            
            for(int j=1;j<=m;j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1])%MOD;
            }
        }
    }

    ll ans = 0;

    for(int i = 1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }

    printf("%lld\n",ans);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

    int tc = 1;
 	//scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)solve(i);
}