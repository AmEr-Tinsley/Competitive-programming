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
vector<string>a(105);

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
int n,m;
int curr;
bool vis[105][105];
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}
void dfs(int x,int y){
    if(vis[x][y])return;
    curr++;
    vis[x][y] = 1;
    for(int i = 0;i<4;i++){
        if(isValid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
void solve(int tc)
{
    
    cin>>n;
    
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }   
    m = sz(a[0]);
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '9')vis[i][j] = true;
        }
    }

    ll ans = 1;
    vector<int>v;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            curr = 0;
            if(!vis[i][j]){
                dfs(i,j);
                v.push_back(curr);
            }
        }
    }

    sort(all(v));
    reverse(all(v));

    cout<<(ll)v[0] * v[1] * v[2]<<endl;
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