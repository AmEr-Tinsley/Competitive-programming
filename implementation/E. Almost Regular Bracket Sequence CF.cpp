   //                                                   ¯\_(ツ)_/¯               
  //#pragma GCC optimize("Ofast")												 
 //#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  
//#pragma GCC optimize("unroll-loops")                                             
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
#define pi pair<int,int>
const int N=1e6+5,MAX=3e7,MOD=998244353;
 
using namespace std;

string str;
int q,l,r,n;
pair<pi,int> seg[4*N];
int ans;
pair<pi,int> combine( const pair<pi,int> &a , const pair<pi,int> &b){

		pair<pi,int> ret;

		int comp = min(a.first.first,b.first.second);

		ret.second = comp + a.second + b.second;
		ret.first.first = a.first.first - comp + b.first.first;
		ret.first.second = a.first.second + b.first.second - comp;

		return ret;
}

void build(int indx,int l,int r){

	if(l==r){seg[indx].first.first = (str[l]=='(');seg[indx].first.second =(str[l]==')');seg[indx].second=0;return;}

	build(indx*2,l,(l+r)/2);
	build(indx*2+1,(l+r)/2+1,r);
	seg[indx]=combine(seg[indx*2],seg[indx*2+1]);
}

void update(int indx,int l,int r,int pos){

	  if(l==r){

	  	   seg[indx].first.first = abs(seg[indx].first.first-1);
	  	   seg[indx].first.second = abs(seg[indx].first.second-1);
	  	   return;
	  }

	  if(pos<=(l+r)/2)update(indx*2,l,(l+r)/2,pos);
	  else update(indx*2+1,(l+r)/2+1,r,pos);
	  seg[indx]=combine(seg[indx*2],seg[indx*2+1]);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
     freopen("test.txt","r",stdin);
#endif 

     cin>>n>>str;

     build(1,0,n-1);


     for(int i=0;i<n;i++){

     	  update(1,0,n-1,i);
     	  if(seg[1].second *2 == n)ans++;
     	  update(1,0,n-1,i);
     }

     
    	cout<<ans<<"\n";
}