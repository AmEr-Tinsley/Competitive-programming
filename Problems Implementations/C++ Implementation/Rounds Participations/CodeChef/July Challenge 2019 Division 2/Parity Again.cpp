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
const int N=3e5+5,MAX=3e7,MOD=1e9+7;
 
int tc,n,x,q;



void solve(){
	
	scanf("%d",&q);
	set<int>s;
	int o = 0 , e = 0; 
	while(q--){
		scanf("%d",&x);
		vector<int>toadd;
		if(s.find(x)==s.end()){
			for(auto c : s){
				if(s.find(c^x)==s.end()){
					if(__builtin_popcount(c^x)%2)o++;
					else e++;
					toadd.pb(c^x);
				}
			}
			for(auto c : toadd)s.insert(c);
			if(__builtin_popcount(x)%2)o++;
			else e++;
			s.insert(x);
		}

		printf("%d %d\n",e,o );
	}
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	scanf("%d",&tc);

    	while(tc--)solve();
    	

}