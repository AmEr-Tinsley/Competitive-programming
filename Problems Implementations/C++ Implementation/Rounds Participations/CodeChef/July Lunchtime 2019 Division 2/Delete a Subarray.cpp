#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
const int N=1e5+5,MAX=3e7,MOD=1e9+7;
int tc;
 void solve(){
 	int n;
 	scanf("%d",&n);
 	std::vector<int> a(n+18);
 	a[0]=-1e9-2;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        
        int l=1,r=n;
        for(int i=2;i<=n;i++){
            
            if (a[i]>a[i-1])
                l=i;
            else
                break;
        }
        for(int i=n-1;i>=1;i--){
            
            if (a[i]>=a[i+1]){
                break;
            }
            r=i;
        }
        ll ans = 0;
        for(int i=0;i<=l;i++){
            
            while(r<=n){
                if (a[i]<a[r])
                    break;
                r++;
            }
           
            ans+=(n-r);
            
            if (i)
                ans++;
            if (r!=i+1)
                ans++;
        }
        
        printf("%lld\n",ans);

 }

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	
	scanf("%d",&tc);

	while(tc--)solve();
}