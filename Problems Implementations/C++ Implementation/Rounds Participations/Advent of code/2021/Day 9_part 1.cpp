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
vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
int n,m;
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}

void solve(int tc)
{
    cin>>n;
    vector<string>a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }   
    m = sz(a[0]);
    int ans = 0;
    for(int i = 0;i<n;i++){
        
        for(int j=0;j<m;j++){
            int cnt = 0;
            int wa = 0;
            for(int k = 0;k<4;k++){
                if(isValid(i+dx[k],j+dy[k])){
                    wa++;
                    if(a[i+dx[k]][j+dy[k]] > a[i][j])cnt++;
                }
            }
            if(wa == cnt){
                ans+=(a[i][j] - '0' + 1);
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