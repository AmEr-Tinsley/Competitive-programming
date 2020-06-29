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
        int tc;
        cin>>tc;

        while(tc--){
            string a;   
            cin>>a;
            if(a=="1" || a=="4" || a == "78"){
                cout<<"+"<<endl;
            }
            else if(sz(a)>=2 && a[sz(a)-2] == '3' && a.back() == '5'){
                cout<<"-"<<endl;
            }
            else if(sz(a)>=2 && a[0]=='9' && a.back() == '4'){
                cout<<"*"<<endl;
            }
            else    cout<<"?"<<endl;
        }
        
        
}