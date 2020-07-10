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

ll memo[20][20];
int n,k;
ll solve(int indx,int last){
    if(indx == n)return 1;
    ll &ret = memo[indx][last];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0;i < k;i++){
        if(!i && !last)continue;
        ret+=solve(indx+1,i);
    }
    return ret;
}
int main(){
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        file();
        scanf("%d %d",&n,&k);
        memset(memo,-1,sizeof(memo));
        printf("%lld\n",solve(0,0));
}