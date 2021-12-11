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
const int DAYS = 100;
vector<vector<int>>a(10);
bool vis[10][10];
int n;
int ans;
vector<int> dx = {1,-1,0,0,1,-1,1,-1};
vector<int> dy = {0,0,1,-1,1,-1,-1,1};
bool isValid(int x,int y){
    return x >= 0 && x < n && y >=0 && y < n;
}
void go(int x,int y){
    a[x][y]++;
    if(a[x][y] > 9)ans++,vis[x][y] = true;
    else  return;
    for(int i = 0;i<8;i++){
        int nextX = x + dx[i] , nextY = y + dy[i];
        if(isValid(nextX,nextY) && !vis[nextX][nextY]){
            go(nextX,nextY);
        }
    }
}
void solve(int tc)
{
    cin>>n;
    for(int i = 0;i<n;i++){
        string x;
        cin>>x;
        for(auto c : x){
            a[i].pb(c - '0');
        }
    }

    for(int i = 0;i < DAYS;i++){

        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                vis[j][k] = 0;
                a[j][k]++;
            }
        }

        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                if(a[j][k] > 9 && !vis[j][k]){
                    go(j,k);
                }
            }
        }

        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                if(a[j][k] > 9){
                    a[j][k] = 0;
                }
            }
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