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
vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,1,-1};

bool isValid(int x,int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void solve(int tc)
{
    cin>>n;
    vector<string>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    for(int k = 1;k<=4;k++){
        for(int i = 0;i<n;i++){
            string x = a[i];
            for(int j = 0;j<sz(x);j++){
                if((a[i][j]-'0') + k == 9)x[j] = '9';
                else x[j] = char('0' +  ((a[i][j]-'0') + k)%9);
            }
            a.pb(x);
        }
    }
    m = sz(a[0]);
    n = sz(a);
    for(int i=0;i<n;i++){
        for(int k =1;k<=4;k++){
            for(int j=0;j<m;j++){
                char x;
                if((a[i][j]-'0') + k == 9)x = '9';
                else x = char('0' +  ((a[i][j]-'0') + k)%9);
                a[i].pb(x);
            }
        }
    }
    m = sz(a[0]);

    for(auto x : a)cout<<x<<endl;
    vector<vector<int>>best(n,vector<int>(m,1e9));
    best[0][0] = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{0,0}});
    while(!q.empty()){
        int x = q.top().second.first , y = q.top().second.second, w =q.top().first;
        q.pop();
        for(int i = 0;i<4;i++){
            int newX = x + dx[i] , newY = y + dy[i];
            if(isValid(newX,newY) && best[newX][newY] > w + a[newX][newY] - '0'){
                best[newX][newY] = w + a[newX][newY] - '0';
                q.push({best[newX][newY],{newX,newY}});
            }
        }
    }
    cout<<best[n-1][m - 1]<<endl;
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