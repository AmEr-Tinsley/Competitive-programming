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
        
        scanf("%d",&tc);

        while(tc--){
            int n;
            scanf("%d",&n);
            std::vector<int> a(n);
            for(int i=0;i<n;i++)scanf("%d",&a[i]);
            sort(all(a));
            int mid = (a[0]+a.back())/2;
            int ans = (a.back()-a[0])*2;
            printf("%d\n",ans );
        }
        
        
}