#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

void solve(int tc){
    int n,d;
    scanf("%d %d",&n,&d);
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;i++)scanf("%d %d",&a[i].first,&a[i].second);
    sort(all(a));
    
    vector<ll>prefix(n);
    for(int i = 0;i<n;i++){
        prefix[i] = a[i].second;
        if(i)prefix[i]+=prefix[i-1];
    }
    ll ans = 0;

    for(int i = 0;i<n;i++){
        int l = i , r = n-1;
        int pos = i;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[i].first + d > a[mid].first){
                l = mid+1;
                pos = mid;
            }else{
                r = mid-1;
            }
        }
        if(i == 0){
            ans = max(ans,prefix[pos]);
        }else{
            ans = max(ans,prefix[pos] - prefix[i-1]);
        }
    }
    printf("%lld\n",ans );
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