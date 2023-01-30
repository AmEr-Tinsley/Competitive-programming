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
    int n,q;
    scanf("%d %d",&n,&q);

    vector<int>a(n);

    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    sort(all(a));
    reverse(all(a));
    vector<int>cnt(n+1);
    for(int i = 0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        cnt[l]++;
        cnt[r]--;
    }

    for(int i = 1;i<n;i++){
        cnt[i]+=cnt[i-1];
    }

    sort(all(cnt));
    reverse(all(cnt));
    int curr = 0;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ans += (ll)a[curr++] * cnt[i];
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