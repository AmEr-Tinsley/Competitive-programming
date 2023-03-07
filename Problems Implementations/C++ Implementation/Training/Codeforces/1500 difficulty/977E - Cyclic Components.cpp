#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;

std::vector<int> g[N];
bool vis[N];
bool dfs(int u){
    if(sz(g[u]) != 2){
        return 0;
    }
    vis[u] = 1;
    bool ret = true;
    for(auto v : g[u]){
        if(vis[v])continue;
        ret &= dfs(v);
    }
    return ret;
}
void solve(int tc){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(vis[i])continue;
        ans += int(dfs(i));
    }

    printf("%d\n",ans );
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