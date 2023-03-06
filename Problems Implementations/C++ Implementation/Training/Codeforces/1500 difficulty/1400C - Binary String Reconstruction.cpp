#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;

void solve(int tc){
    string a;
    int k;

    cin>>a>>k;
    int n = sz(a);
    string ans(n,'1');

    for(int i = 0;i<n;i++){
        if((i + k) < n && a[i+k] == '0'){
            ans[i] = '0';
        }

        if((i-k) >= 0 && a[i-k] == '0'){
            ans[i] = '0';
        } 
    }

    for(int i = 0;i<n;i++){
        if(a[i] == '0')continue;
        bool yes = false;
        yes |= ((i+k) < n && ans[i+k] == '1');
        yes |= ((i-k) >= 0 && ans[i-k] == '1');

        if(yes)continue;
        cout<<"-1\n";
        return;
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