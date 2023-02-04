#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5005;

void solve(int tc){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    ll curr = 1;
    while(curr <= n){
        if((n - curr)%b == 0){
            printf("Yes\n");
            return;
        }
        curr *= a;
        if(a == 1)break;
    }
    printf("No\n");
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

// 1 b a x+b x*a