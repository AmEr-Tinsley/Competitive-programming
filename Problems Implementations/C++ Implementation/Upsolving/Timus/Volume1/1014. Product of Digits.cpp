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
        if(n==1)return !printf("%d\n",n);
        if(n==0)return !printf("10\n");
        std::vector<int> ans;
        for(int i=9;i>=2;i--){
            while(n%i == 0)ans.pb(i),n/=i;
        }
        if(n!=1)return !printf("-1\n");
        reverse(all(ans));
        for(auto x : ans)printf("%d",x);
        printf("\n");
}