#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
const int N=1e6+5,MOD=1e9+7,MAX=1e5,offset=37005;

const ll mod = 998244353;

vector<ll> v;

ll poww(ll x, ll p) {
    ll ans = 1;
    while (p) {
        if (p % 2) {
            ans = (ans * x) % mod;
            --p;
        }
        else {
            x = (x * x) % mod;
            p /= 2;
        }
    }
    return ans;
}
 
ll n;

std::vector<ll> a, in;
 
ll wa(ll n, ll k) {
    return (a[n] * in[k]) % mod;
}
int  main()
{
   
    #ifndef ONLINE_JUDGE
     freopen("test.txt","r",stdin);
    #endif
     
    cin >> n;

    a.assign(n+1,1);
    in.assign(n+1,1);
    
    for (ll i = 1; i <= n; ++i) {
        a[i] = (a[i - 1] * i) % mod;
        in[i] = poww(a[i], mod - 2);
    }
    
    ll ans = a[n];
    
    for (ll k = 2; k < n; ++k) 
        ans = (ans + (wa(n, k) * (((n - k) * (k - 1)) % mod))) % mod;
   
   cout << ans << "\n";

 return 0;
}
