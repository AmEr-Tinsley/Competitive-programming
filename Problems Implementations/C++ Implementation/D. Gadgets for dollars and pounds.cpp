#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
const int N=1e6+5,MAX=3e7,MOD=1e9+7;
 
using namespace std;

int n,m,k;
ll s;

std::vector<pair<int,int>> Type1,Type2;
std::vector<pair<int,int>> ans;
int dollar[N],pound[N],t,x;

bool check(int x){

	 ll rem = s;

	 std::vector<pair<int,int>> canbe;

	 pair<int,int> best_dollar{1e9,0} , best_pound = {1e9,0};

	 for(int i=0;i<=x;i++){

	 	  if(best_dollar.first > dollar[i])best_dollar={dollar[i],i};
	 	  if(best_pound.first > pound[i]) best_pound={pound[i],i};
	 }

	 std::vector<pair<ll,pair<int,int>>> both;

	 for(int i=0;i<sz(Type1);i++){

	 	  both.pb({(ll)Type1[i].first*best_dollar.first,{Type1[i].second,best_dollar.second}});
	 }
	 for(int i=0;i<sz(Type2);i++){

	 	  both.pb({(ll)Type2[i].first*best_pound.first,{Type2[i].second,best_pound.second}});
	 }

	 sort(all(both));

	 for(int i=0;i<sz(both);i++){

	 		if(rem < both[i].first || sz(canbe)==k)break;

            rem-=both[i].first;
            canbe.pb(both[i].second);
	 }

	 if(sz(canbe)==k){ans.swap(canbe);return true;}
	 return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
      freopen("test.txt","r",stdin);
#endif 
        

        scanf("%d %d %d %lld",&n,&m,&k,&s);

        for(int i=0;i<n;i++)scanf("%d",&dollar[i]);
        for(int i=0;i<n;i++)scanf("%d",&pound[i]);

        for(int i=0;i<m;i++){

        	 scanf("%d %d",&t,&x);

        	 if(t==1){

        	 	 Type1.pb({x,i});
        	 }
        	 else{

        	 	 Type2.pb({x,i});
        	 }
        }

        int l=0,r=n-1,anss = -1;

        while(l<=r){

        	 int mid=(l+r)/2;

        	 if(check(mid)){
                  r=mid-1;
                  anss=mid+1;
        	 }
        	 else{
        	 	  l=mid+1;
        	 }
        }

        printf("%d\n",anss );

        if(anss==-1)return 0;

        for(auto p : ans){
        	 printf("%d %d\n",p.first+1,p.second+1);
        }
       
       	
 }