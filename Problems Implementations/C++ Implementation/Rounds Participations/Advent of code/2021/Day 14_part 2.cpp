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

void solve(int tc)
{
    string a;
    cin>>a;
    
    string x;
    char b;
    map<string,char>wa;
    map<string,ll>occ;
    while(cin>>x>>b){
        wa[x] = b;
    }
    map<char,ll>dec;
    for(int i = 0;i<sz(a)-1;i++){
        x = "";
        x+=a[i];x+=a[i+1];
        occ[x]++;
    }
    
    
    for(int i =0;i<40;i++){
        vector<string>toReset;
        vector<pair<string,ll>>toAdd;
        for(auto p : occ){
            if(wa.count(p.first)){
                x = "";
                x+=p.first[0];x+=wa[p.first];
                toAdd.pb({x,p.second});
                x="";
                x+=wa[p.first];x+=p.first[1];
                toAdd.pb({x,p.second});
                toReset.pb(p.first);
            }
        }
        for(auto x : toReset)occ[x] = 0;
        for(auto p : toAdd)occ[p.first]+=p.second;
    }

    ll mx = 0,mn = 1e18;
    map<char,ll>freq;
    for(auto p:occ){
        freq[p.first[0]]+=p.second;
        freq[p.first[1]]+=p.second;
    }

    for(auto p : freq){
        mx = max(mx,p.second);
        mn = min(mn,p.second);
    }

    cout<<(mx - mn)/2<<endl;
    
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