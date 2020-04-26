#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
const int N=1e6+5,MAX=3e7,MOD=1e9+7;
 
using namespace std;
 
string str;
int k;

int pref[N];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("test.txt","r",stdin);
    #endif

     cin>>str>>k;

     int candy=0 , snow=0 , n = sz(str);

     for(int i = 0; i<n;i++){

     	   pref[i]=(str[i]!='*' && str[i]!='?');
     	   if(i)pref[i]+=pref[i-1];
     }

     string ans ;

     bool stop = false;

     for(int i=0;i<n;i++){
          
     	  if((str[i]=='*' || str[i] == '?') && stop)continue;

     	  if(str[i]!='*' && str[i]!='?')ans.pb(str[i]);

     	  if(str[i] == '*' && sz(ans)){
                   int wa = k-(pref[n-1]-pref[i]+sz(ans));
                   if(wa == 0){stop = true;continue;}
                   if(wa < 0)ans.pop_back();
                   else{
                   while(wa--)ans.pb(ans.back());
                   stop = true;
                  }
     	  }
     	  if(str[i]=='?' && sz(ans)){
     	  	    int wa = k-(pref[n-1]-pref[i]+sz(ans));
     	  	    if(wa == 0){stop = true;continue;}
     	  	    if(wa < 0)ans.pop_back();
     	  }
     }

     if(sz(ans) != k)cout<<"Impossible";
     else cout<<ans<<"\n";
     
}