#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+7;

void solve(int tc){
    string a = "codeforces";

    vector<int>cnt(sz(a));

    ll k;

    cin>>k;

    while(1){

        for(int i = 1;i<=sz(a);i++){
            ll curr = 1;

            for(int j = 0;j<sz(a);j++){
                if(j < i){
                    curr *= (cnt[j] + 1);
                }else{
                    curr *= cnt[j];
                }
            }

            if(curr >= k){
                string ans = "";
                for(int j =0;j<sz(a);j++){
                    if(j < i)cnt[j]++;
                    int w = max(cnt[j],1);
                    while(w--){
                        ans += a[j];
                    }
                }

                cout<<ans<<endl;
                return;
            }
        }

        for(int i = 0;i<sz(a);i++)cnt[i]++;
    }

    
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