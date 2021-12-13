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
int n,m;

void solve(int tc)
{
    int k,q;

    cin>>k>>q;
    map<pair<int,int>,bool>wa;
    for(int i= 0;i<k;i++){
        int x,y;
        cin>>y>>x;
        m = max(m,y + 1);
        n = max(n,x + 1);
        wa[{x,y}] = true;
    }

    vector<string>a(n,string(m,'.'));

    for(auto p : wa){
        int x = p.first.first, y = p.first.second;
        a[x][y] = '#';
    }

    for(int i = 0;i<1;i++){
        char c;
        int w;
        cin>>c>>w;

        if(c == 'x'){
            int l = 0,r = n-1;
            while(l<r && r>w){
                for(int j = 0;j<m;j++){
                    if(a[r][j] == '#')a[l][j] = '#';
                }
                l++;
                r--;
            }
            n = w+1;
        }else{
            int l = 0,r = m-1;
            while(l<r && r>w){
                for(int j = 0;j<n;j++){
                    if(a[j][r] == '#')a[j][l] = '#';
                }
                l++;
                r--;
            }
            m = w+1;
        }
    }

    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            ans+=(a[i][j] == '#');
        }
    }

    cout<<ans<<endl;
    
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