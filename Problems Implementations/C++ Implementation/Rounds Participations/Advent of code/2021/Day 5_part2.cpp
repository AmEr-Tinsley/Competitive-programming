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
    int n;

    scanf("%d",&n);
    vector<vector<int>>cnt(5000,vector<int>(5000));
    for(int i = 0;i<n;i++){
        int x1,y1,x2,y2;

        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);

        if(x1 == x2 || y1 == y2){
            for(int j = min(x1,x2);j<=max(x2,x1);j++){
                for(int k = min(y1,y2);k<=max(y1,y2);k++){
                    cnt[j][k]++;
                }
            }
        }
        else{
            int inc_x = 1 , inc_y = 1;
            if(x1 > x2){
                inc_x = -1;
            }
            if(y1 > y2)inc_y = -1;
            while(x1 != x2 && y1 !=y2){
                cnt[x1][y1]++;
                x1+=inc_x;
                y1+=inc_y;
            }
            cnt[x1][y1]++;
        }
    }
    int ans = 0;
    for(auto v : cnt){
        for(auto x : v){
            if(x > 1){
                ans++;
            }
        }
    }

    printf("%d\n",ans);    
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