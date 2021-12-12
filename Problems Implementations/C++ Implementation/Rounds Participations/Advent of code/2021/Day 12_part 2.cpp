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

map<string,vector<string>>g;
map<string,int>visited;
bool isSmallCave(string s){
    return s[0] >= 'a' && s[0] <= 'z';
}
int go(string u){
    int cnt = 0;
    if(u == "end")return 1;
    for(auto v : g[u]){
        if(isSmallCave(v)){
            bool validToVisit = v != "start";
            if(visited[v] > 1)continue;
            else if(visited[v] == 1){
                for(auto p : visited){
                    if(isSmallCave(p.first) && p.second > 1)validToVisit = false;
                }
            }
            if(validToVisit){
                visited[v]++;
                cnt+=go(v);
                visited[v]--;
            }
        }
        else{
            cnt+=go(v);
        }
    }
    return cnt;
}

void solve(int tc)
{
    string a,b;

    while(cin>>a>>b){
        g[a].pb(b);
        g[b].pb(a);
    }
    visited["start"] = 1;
    int ans = go("start");

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