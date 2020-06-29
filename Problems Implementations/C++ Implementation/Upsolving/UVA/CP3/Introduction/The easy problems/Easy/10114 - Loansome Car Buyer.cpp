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
        
        int k,n;
        double a,b;
        while(scanf("%d %lf %lf %d",&k,&a,&b,&n) && k > 0){
            double dwn =  0;
            int ans;
            std::vector<double> v(k+1,-1);
            for(int i = 0;i<n;i++){
                int m;
                double md;
                scanf("%d %lf",&m,&md);
                v[m] = 1-md;
            }
            double eachmonth = b/k;
            double curr = b+a;
            for(int i = 0 ; i <= k ;i++){
                if(v[i] == -1)v[i]=v[i-1];
                if(i)b -= eachmonth;
                curr = curr * v[i];
                if(b < curr){
                    ans = i;
                    break;
                }
            }
            printf("%d ",ans );
            if(ans == 1)printf("month\n");
            else    printf("months\n");
        }
        
        
}