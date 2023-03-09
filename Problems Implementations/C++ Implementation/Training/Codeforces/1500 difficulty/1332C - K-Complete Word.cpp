#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;

int n,k;
string a;
std::vector<int> g[N];
int cnt[26];
bool vis[N];
void dfs(int u){
    cnt[a[u]-'a']++;
    vis[u] = 1;
    for(auto v : g[u]){
        if(vis[v])continue;
        dfs(v);
    }
}
void solve(int tc){
    cin>>n>>k>>a;
    for(int i = 0;i<n;i++)g[i].clear(),vis[i] = 0;

    for(int i = 0;i<n;i++){
        if((n-i-1) < n){
            g[i].pb(n-i-1);
        }
        if((i + k) < n){
            g[i].pb(i+k);
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(vis[i])continue;
        for(int j = 0;j<26;j++)cnt[j] = 0;
        dfs(i);
        int mx = 0;
        int c = 0;
        for(int j = 0;j<26;j++){
            mx = max(mx,cnt[j]);
            c += cnt[j];
        }

        ans += (c-mx);
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin>>tc;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}
