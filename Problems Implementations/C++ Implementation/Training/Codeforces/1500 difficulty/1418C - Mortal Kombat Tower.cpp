#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;


void solve(int tc){
    int n;
    scanf("%d",&n);
    std::vector<int> a(n);
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);

    vector<vector<int>>dp(n,vector<int>(2,n));
    dp[0][1] = dp[0][0] = int(a[0] == 1);

    for(int i = 1;i<n;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][0] + int(a[i] == 1);
        if(i > 1){
            dp[i][0] = min(dp[i][0],dp[i-2][1]);
            dp[i][1] = min(dp[i][1],dp[i-2][0] + int(a[i] == 1) + int(a[i-1] == 1));
        }
    }

    printf("%d\n",min(dp[n-1][0],dp[n-1][1]) );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}
