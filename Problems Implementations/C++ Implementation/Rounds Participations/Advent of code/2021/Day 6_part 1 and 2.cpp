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
const int NB_DAYS = 256; //80 for part 1 and 256 for part2
void solve(int tc)
{
    int n;

    scanf("%d",&n);

    vector<ll> freq(9);

    for(int i = 0,x;i<n;i++)scanf("%d",&x),freq[x]++;

    for(int day = 1;day<=NB_DAYS;day++){
        ll to_recycle = freq[0];
        for(int i = 1;i<=8;i++)freq[i - 1]+=freq[i],freq[i] = 0;
        freq[6]+=to_recycle;
        freq[8]+=to_recycle;
        freq[0]-=to_recycle;
    }
    ll ans = 0;
    for(int i = 0;i<=8;i++)ans+=freq[i];

    printf("%lld\n",ans);
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