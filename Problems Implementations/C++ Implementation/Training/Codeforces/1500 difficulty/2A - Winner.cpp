#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

void solve(int tc){
    int n;

    cin>>n;

    string ans;
    map<string,int>score;
    int mx = INT_MIN;
    map<int,vector<pair<int,string>>>ev;
    for(int i = 0;i<n;i++){
        string who;
        int sc;
        cin>>who>>sc;
        score[who]+=sc;
        ev[score[who]].pb({i,who});
    }
    set<string>s;
    for(auto p : score){
        if(mx < p.second){
            mx = p.second;
            s.clear();
            s.insert(p.first);
        }else if(mx == p.second){
            s.insert(p.first);
        }
    }
    int mn = INT_MAX;

    for(int i = 1000000;i>=mx;i--){
        for(auto p : ev[i]){
            if(s.count(p.second) && mn > p.first){
                ans = p.second;
                mn = p.first;
            }
        }
    }
    cout<<ans<<endl;
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