#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;
int root[N];
int find(int u){
    if(root[u] == u)return u;
    return root[u] = find(root[u]);
}
void solve(int tc){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)root[i] = i;
    int ans = 0;
    for(int i = 0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        int p1 = find(u),p2 = find(v);
        if(p1 == p2){
            ans++;
        }else{
            root[p1] = p2;
        }
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