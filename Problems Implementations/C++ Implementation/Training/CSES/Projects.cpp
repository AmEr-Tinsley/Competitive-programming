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

struct project
{
    int l, r, x;
};

void solve(int tc)
{
    int n;

    scanf("%d", &n);

    vector<project> a(n);

    for (auto &p : a)
    {
        scanf("%d %d %d", &p.l, &p.r, &p.x);
    }

    sort(all(a), [](const project &a, const project &b){ return a.l < b.l; });

    vector<ll> dp(n + 1);
    for (int i = sz(a) - 1; i >= 0; i--)
    {
        auto it = upper_bound(all(a), a[i].r, [](int r, const project &p){ return p.l > r; });

        if (it == a.end())
        {

            dp[i] = max(dp[i + 1],(ll)a[i].x);
        }
        else
        {
            int indx = it - a.begin();
            dp[i] = max(dp[i + 1], dp[indx] + a[i].x);
        }
    }

    printf("%lld\n", dp[0]);
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