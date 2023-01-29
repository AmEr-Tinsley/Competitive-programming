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

    scanf("%d",&n);

    vector<ll>x(n),h(n);
    for(int i = 0;i<n;i++)scanf("%lld %lld",&x[i],&h[i]);
    if(n == 1){
        printf("1\n");
        return;
    }
    ll last = x[0];
    int ans = 2;
    for(int i = 1;i<n-1;i++){
        if((x[i] - h[i]) > last){
            ans++;
            last = x[i];
        }else if( (x[i] + h[i]) < x[i+1]){
            ans++;
            last = x[i] + h[i];
        }else{
            last = x[i];
        }
    } 
    printf("%d\n",ans);
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