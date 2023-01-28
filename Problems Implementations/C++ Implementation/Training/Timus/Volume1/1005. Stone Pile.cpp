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

int main(){
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        file();
        
        int n;

        scanf("%d",&n);
        int sum = 0;
        std::vector<int> a(n);
        for(auto &x:a)scanf("%d",&x),sum+=x;
        int ans = 1e9;
        for(int i=0;i<(1<<n);i++){
            int x = 0;
            for(int j=0;j<n;j++)if(i & (1<<j))x+=a[j];
            int y = sum - x;
            ans = min(ans,abs(y-x));
        }
        printf("%d\n",ans );
}