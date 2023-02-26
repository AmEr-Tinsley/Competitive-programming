#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;

void solve(int tc){
    int n;

    scanf("%d",&n);

    std::vector<int> a(n);
    ll sum = 0;
    for(int i = 0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
    if(sum % 2){
        puts("NO");
        return;
    }

    sort(all(a));

    puts((sum - a[n-1]) >= a[n-1] ? "YES" : "NO");
    
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