#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

int lg(int x){
    for(int i = 1;;i++){
        x-=(1<<(i-1));
        if(x<=0){
            return i;
        }
    }
}
void solve(int tc){
    int n;
    scanf("%d",&n);

    int mx = INT_MIN;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(i && x < mx){
            ans = max(ans,lg(mx-x));
        }
        mx = max(mx,x);
    }
    printf("%d\n",ans );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}