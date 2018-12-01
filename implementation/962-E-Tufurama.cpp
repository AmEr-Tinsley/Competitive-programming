#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
const int N=1e6+5,MOD=1e9+7;

int n,a[N];
ll ans;
std::vector<int > seg[4*N];

void build(int indx ,int l,int r){

    if(l==r)seg[indx].pb(a[l]);
    else{
       build(indx*2,l,(l+r)/2);
       build(indx*2+1,(l+r)/2+1,r);
       merge(all(seg[indx*2]),all(seg[indx*2+1]),back_inserter(seg[indx]));
    }
}

int  get(int indx,int l,int r,int i,int j,int val){
    std::vector<int > ret;

      if(i>r ||j<l)return 0;
     if(l>=i && r<=j){
         return (seg[indx].end()-lower_bound(all(seg[indx]),val));
     }

     int  a = get(indx*2,l,(l+r)/2,i,j,val);
     int  b = get(indx*2+1,(l+r)/2+1,r,i,j,val);

     return a+b;
}

int main(){

  #ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
  #endif
      
       scanf("%d",&n);

       for(int i=0;i<n;i++)scanf("%d",&a[i]),a[i]--;

       build(1,0,n-1);

      for(int i=1;i<n;i++){
           
         ans+= get(1,0,n-1,0,min(a[i],i-1),i);
      }

      printf("%lld\n",ans );
      
    
}