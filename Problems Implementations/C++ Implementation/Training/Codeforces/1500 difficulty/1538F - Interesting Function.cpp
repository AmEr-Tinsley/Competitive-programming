#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5+7;

void solve(int tc){
    int x,y;

    scanf("%d %d",&x,&y);

    int ans = 0;
    while(y){
        ans+=(y-x);
        y/=10;
        x/=10;
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