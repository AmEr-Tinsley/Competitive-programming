//                             ¯\_(ツ)_/¯  
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
//using namespace  __gnu_pbds;

//typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
}
int tc;
const int N = 1e6 + 5, M = 2e6 + 5, MOD = 1e9 + 7, OO = 1e9 + 7;
const ll INF = 2e18;

void solve(int tc)
{
    ll ox = 0,co2 = 0;
    vector<string>a;
    string x;
    while(cin>>x){
        a.pb(x);
    }
    
    int n = sz(a);
    vector<bool>erased(n);
    // ox
    for(int j = 0;j<sz(a[0]);j++){
        int zeros = 0 , ones = 0;
        for(int i = 0;i<n;i++){
            if(!erased[i]){
                zeros+=(a[i][j] == '0');
                ones+=(a[i][j] == '1');
            }
        }
        if(ones + zeros == 1)break;
        
        if(ones >= zeros){
            for(int i = 0;i<n;i++){
                if(a[i][j] == '0')erased[i] = true;
            }
        }
        else{
            for(int i = 0;i<n;i++){
                if(a[i][j] == '1')erased[i] = true;
            }
        }
    }

    for(int i = 0;i<n;i++){
        if(!erased[i]){
            string x = a[i];
            reverse(all(x));
            for(int j =0;j<sz(x);j++){
                if(x[j] == '1')ox+=(1<<j);
            }
        }
    }
    
    //co2
    for(int i = 0;i<n;i++)erased[i] = false;

    for(int j = 0;j<sz(a[0]);j++){
        int zeros = 0 , ones = 0;
        for(int i = 0;i<n;i++){
            if(!erased[i]){
                zeros+=(a[i][j] == '0');
                ones+=(a[i][j] == '1');
            }
        }
        if(ones + zeros == 1)break;
        if(ones >= zeros){
            for(int i = 0;i<n;i++){
                if(a[i][j] == '1')erased[i] = true;
            }
        }
        else{
            for(int i = 0;i<n;i++){
                if(a[i][j] == '0')erased[i] = true;
            }
        }
    }

    for(int i = 0;i<n;i++){
        if(!erased[i]){
            string x = a[i];
            reverse(all(x));
            for(int j =0;j<sz(x);j++){
                if(x[j] == '1')co2+=(1<<j);
            }
        }
    }


    cout<<ox*co2<<endl;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    file();
 
    int tc = 1;
    //scanf("%d",&tc);
    for (int i = 1; i <= tc; i++)
        solve(i);
}