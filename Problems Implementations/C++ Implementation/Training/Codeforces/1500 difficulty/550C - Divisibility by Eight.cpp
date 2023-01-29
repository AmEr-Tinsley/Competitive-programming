#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;
int countDigits(int x){
    int ret = 0;
    while(x){
        ret++;
        x/=10;
    }
    return ret;
}
void solve(int tc){
    vector<string>div;
    int c = 0;
    while(countDigits(8*c) <= 3){
        div.pb(to_string(8*c));
        c++;
    }
    string a;
    cin>>a;
    for(auto s : div){
        int i = 0;
        int n = sz(s);
        for(auto c : a){
            if(c == s[i]){
                i++;
            }
            if(i == n)break;
        }
        if(i == n){
            cout<<"YES\n";
            cout<<s<<endl;
            return;
        }
    }
    puts("NO");
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