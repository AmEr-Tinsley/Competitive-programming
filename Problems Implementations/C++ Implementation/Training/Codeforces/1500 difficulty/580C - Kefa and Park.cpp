#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

int n,m;
vector<int>g[N];
int a[N];

int dfs(int u,int c,int p){
    if(c > m)return 0;
    if(sz(g[u]) == 1 && u != 1)return 1;
    int ret = 0;
    for(auto v : g[u]){
        if(v == p)continue;
        if(a[v] == 1){
            ret += dfs(v,c+1,u);
        }else{
            ret += dfs(v,0,u);
        }
    }
    return ret;
}
void solve(int tc){
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1,u,v;i<n;i++)scanf("%d %d",&u,&v),g[u].pb(v),g[v].pb(u);
    printf("%d\n",dfs(1,a[1],0));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}