#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+7;

void solve(int tc){
    string a;
    cin>>a;
    vector<int>occ(10);
    for(int i = 0;i<sz(a);i++){
        occ[a[i]-'0']++;
    }
    int ans = sz(a) - 2;
    
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(i == j){
                ans = min(sz(a) - occ[i],ans);
                continue;
            }
            int cnt = 0;
            bool wa = true;
            for(auto c : a){
                if(wa && (c - '0') == i){
                    wa = false;
                    cnt++;
                }else if((c - '0') == j && !wa){
                    wa = true;
                    cnt++;
                }
            }
            if(!wa){
                cnt--;
            }
            ans = min(ans,sz(a)-cnt);
        }
    }
    cout<<ans<<endl;
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