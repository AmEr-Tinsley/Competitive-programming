#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

int n;
int a[N];
ll memo[N];

ll go(int indx){
    if(indx >= N)return 0;
    ll ret = memo[indx];
    if(ret != -1)return ret;
    ll choice1 = go(indx+1);
    ll choice2 = go(indx+2) + (ll)indx * a[indx];
    return ret = max(choice1,choice2);
}

void solve(int tc){
    scanf("%d",&n);
    for(int i = 0,x;i<n;i++)scanf("%d",&x),a[x]++;
    memset(memo,-1,sizeof(memo));
    printf("%lld\n",go(1));
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