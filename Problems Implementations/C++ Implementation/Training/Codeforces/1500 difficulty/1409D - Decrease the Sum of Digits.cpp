#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+7;

ll pw(int x,int y){
    ll ret = 1;
    while(y--){
        ret*=x;
    }
    return ret;
}
void solve(int tc){
    string a;
    int s;
    cin>>a>>s;
    reverse(all(a));
    int cnt = 0;
    for(auto c : a)cnt+=(c-'0');
    int carry = 0;
    ll ans = 0;
    for(int i = 0;i<sz(a);i++){
        if(!carry && cnt <= s)break;
        if(a[i] == '0' && !carry)continue;
        if(carry && a[i] == '9'){
            a[i] = '0';
            cnt-=9;
            continue;
        }else if(carry){
            a[i]++;
            cnt++;
            carry = 0;
        }
        if(cnt <= s)break;
        int mxCan = '9' - a[i] + 1;
        carry = 1;
        cnt-= (a[i] - '0');
        ans+=mxCan*pw(10,i);  
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

/*
3
*.*.
*/