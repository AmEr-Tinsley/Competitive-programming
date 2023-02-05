#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+7;
ll dp[10000005][2];
void solve(int tc){
    int n;

    scanf("%d",&n);

    dp[0][0] = 1;

    for(int i = 1;i<=n;i++){
        dp[i][0] = (3*dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2)%MOD;
    }

    printf("%lld\n",dp[n][0] );
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}