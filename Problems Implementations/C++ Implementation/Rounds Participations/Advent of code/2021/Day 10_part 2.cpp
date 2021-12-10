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

bool isClosing(char c){
    return c == ')' || c == ']' || c =='}' || c == '>';
}
void solve(int tc)
{
    map<char,char>wa;
    wa[')'] = '(';
    wa[']'] = '[';
    wa['}'] = '{';
    wa['>'] = '<';
    wa['('] = ')';
    wa['['] = ']';
    wa['{'] = '}';
    wa['<'] = '>';
    map<char,int>score;
    score[')'] = 1;
    score[']'] = 2;
    score['}'] = 3;
    score['>'] = 4;
    string a;
    ll ans = 0;
    vector<ll>v;
    while(cin>>a){
        stack<char>s;
        bool corrupted = false;
        for(auto c : a){
            if(isClosing(c)){
                if(s.empty() || s.top() != wa[c]){
                    corrupted = true;
                    break;
                    
                }
                else if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(c);
            }
        }
        if(s.empty())continue;
        ll sc = 0;
        if(!corrupted){
            while(!s.empty()){
                char c = s.top();
                sc = sc*5 + score[wa[c]];
                s.pop();
            }
        }
        if(sc)v.push_back(sc);
    }
    sort(all(v));
    int n = sz(v);
    cout<<v[n/2]<<endl;
    
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