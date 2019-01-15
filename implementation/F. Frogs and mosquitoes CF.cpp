#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
const int N=1e6+5,MAX=3e7,MOD=1e9+7;
 
using namespace std;

struct Frog
{
	 ll startx , mostrightx ,indx,indx_after_sort;
	
};

bool cmp(Frog &a,Frog &b){

	 return (a.startx < b.startx);
}

int n,m;
int start[N];
Frog frog[N];

Frog seg[4*N];

pair<int,ll> ans[N];

Frog combine(Frog &a , Frog &b){

	  if(a.mostrightx > b.mostrightx)return a;
	  return b;
}
void build(int indx,int l,int r){

	 if(l==r){seg[indx]=frog[l];return;}

	 build(indx*2,l,(l+r)/2);
	 build(indx*2+1,(l+r)/2+1,r);
	 seg[indx]=combine(seg[indx*2],seg[indx*2+1]);
}

void update(int indx,int l,int r,int pos,ll val){

		if(l==r){seg[indx].mostrightx=val;return;}
		if(pos <= (l+r)/2)update(indx*2,l,(l+r)/2,pos,val);
		else update(indx*2+1,(l+r)/2+1,r,pos,val);
		seg[indx]=combine(seg[indx*2],seg[indx*2+1]);
}

Frog get(int indx,int l,int r,int x){
      Frog best;
      best.startx=-1,best.mostrightx=-1,best.indx=-1,best.indx_after_sort=-1;
	 if(l==r){
	 	  if(seg[indx].startx <= x && seg[indx].mostrightx >= x )return seg[indx];
	      return best;
	 }

	 if(seg[indx*2].mostrightx>=x)
	 return get(indx*2,l,(l+r)/2,x);

	 if(seg[indx*2+1].mostrightx>=x)
	   return get(indx*2+1,(l+r)/2+1,r,x);

	 return best;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
      freopen("test.txt","r",stdin);
#endif 
        
        scanf("%d %d",&n,&m);


        for(int i=0;i<n;i++){

        	  scanf("%lld %lld",&frog[i].startx,&frog[i].mostrightx);
        	  start[i]=frog[i].startx;
        	  frog[i].mostrightx+=frog[i].startx;
        	  frog[i].indx=i;
        	  frog[i].indx_after_sort=i;
        	  ans[i].second=frog[i].mostrightx;
        	  
        }

        sort(frog,frog+n,cmp);

        for(int i=0;i<n;i++)frog[i].indx_after_sort=i;

     	build(1,0,n-1);

     	multiset<pair<ll,ll>>notyet;

     	for(int i=0;i<m;i++){
              pair<ll,ll> mos;
     		  scanf("%lld %lld",&mos.first,&mos.second);

     		  Frog best = get(1,0,n-1,mos.first);

     		  if(best.startx == -1)notyet.insert(mos);
     		  else{
     		  	   ans[best.indx].first++;
     		  	   ans[best.indx].second+=mos.second;
     		  	   best.mostrightx+=mos.second;
     		  	   while(!notyet.empty()){

     		  	   	   auto it = notyet.lower_bound({best.startx,-1});

     		  	   	   if(it == notyet.end())break;

     		  	   	   if((*it).first <= best.mostrightx)ans[best.indx].first++,ans[best.indx].second+=(*it).second,best.mostrightx+=(*it).second,notyet.erase(it);
     		  	   	   else break;
     		  	   }

     		  	   update(1,0,n-1,best.indx_after_sort,best.mostrightx);

     		  }
     	}

     	for(int i=0;i<n;i++)printf("%d %lld\n",ans[i].first,ans[i].second-start[i] );
 }