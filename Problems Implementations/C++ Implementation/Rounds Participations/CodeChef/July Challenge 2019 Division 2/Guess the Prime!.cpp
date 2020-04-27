//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long

using namespace std;


using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
const int N=3e5+5,MAX=3e7,MOD=1e9+7;
int n,m,tc,k,ans,a[N],q,x,cnt[10];
 
char s[N];
 
vector<pair<ll,int> >v;
 
vector<int> factor;
void solve(){
	 memset(cnt,0,sizeof cnt);
        factor.clear();
        v.clear();
        bool ok=false;
    	printf("1 63254\n");
    	fflush(stdout);
    	scanf("%d",&x);
    	ll p=4001068516-x;
    	for(int i=2;(ll)i*i<=p;i++){
    		if (p%i==0){
                while(p%i==0)
                    p/=i;
                if (4001068516%i==x)
                    factor.push_back(i);
    		}
    	}
    	if (p!=1 && (4001068516%p==x))
            factor.push_back(p);
        int ask=-1,mn=1e9;
    	for(int i=0;i<(int)factor.size();i++){
            set<int> vis;
//            printf("%d : ",factor[i]);
            for(int j=0;j<(int)factor.size();j++){
                if (i==j)
                    continue;
                int prod=((ll)factor[i]*factor[i])%factor[j];
                if (vis.count(prod)){
//                    printf(" %d|%d ",factor[j],prod );
                    cnt[i]++;
                }
                vis.insert(prod);
            }
//            printf("\n");
    	}
    	for(int i=0;i<(int)factor.size();i++){
            if (cnt[i]<mn)
                ask=factor[i];
            mn=min(mn,cnt[i]);
    	}
    	printf("1 %d\n",ask);
        fflush(stdout);
        scanf("%d",&x);
        v.push_back({(ll)ask*ask,x});
        int cnt=0;
        for(int i=0;i<factor.size();i++){
            int can=factor[i];
            if (v[0].first%can==(ll)v[0].second){
                cnt++;
                ans=can;
            }
        }
        if (cnt!=1)
            x/=0;
        else{
            printf("2 %d\n",ans);
            fflush(stdout);
            scanf("%s",s);
        }
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();

 	scanf("%d",&tc);

 	while(tc--)solve();



}