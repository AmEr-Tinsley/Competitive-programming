//                             ¯\_(ツ)_/¯  
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
//using namespace  __gnu_pbds;

//typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
}
int tc;
const int N = 1e6 + 5, M = 2e6 + 5, MOD = 1e9 + 7, OO = 1e9 + 7;
const ll INF = 2e18;

void solve(int tc)
{
    int n,x;

    scanf("%d %d", &n,&x);

    vector<int> a(n);

    vector<pair<int,int>>dp(1<<n,{1e9,0});

    for(int i = 0;i<n;i++)scanf("%d",&a[i]);

    dp[0] = {1,0};

    for(int i = 1;i < (1<<n) ;i++){
        for(int j =0;j<n;j++){
            if(i & (1<<j)){
                int r = dp[i^(1<<j)].first;
                int w = dp[i^(1<<j)].second;
                if(w + a[j] > x){
                    dp[i] = min(dp[i],{r + 1 , a[j] });
                }
                else{
                    dp[i] = min(dp[i] , {r, w + a[j]});
                }
            }
        }
    }

    printf("%d\n",dp[(1<<n)-1].first);
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file();

    int tc = 1;
    //scanf("%d",&tc);
    for (int i = 1; i <= tc; i++)
        solve(i);
}