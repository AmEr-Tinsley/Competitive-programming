//                             ¯\_(ツ)_/¯   
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mma,ava,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define ll long long
 
 
void file(){
        #ifndef ONLINE_JUDGE
        freopen("test.txt", "r", stdin);
        #endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
std::vector<int> wa;
int sieve[N];
void sievee(){
    for (int x = 2; x < N; x++) {
        if (sieve[x]) continue;
        wa.pb(x);
        for (int u = 2*x; u < N; u += x) {
        sieve[u] = x;
    }
}

}
int main(){
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        file();
        int tc;
        scanf("%d",&tc);
        sievee();
        while(tc--){
            int n;
            scanf("%d",&n);
            printf("%d\n",wa[n-1]);
        }
}