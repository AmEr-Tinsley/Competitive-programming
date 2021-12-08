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
string x;
map<string,int>wa;
// 5 : 5,2,3
// 6 : 6,0,9
vector<string> a(10);
void find_six(){
    map<char,int> one_chars;
    for(auto x: a){
        if(sz(x) == 2){
            for(auto c : x){
                one_chars[c]++;
            }
        }
    }

    for(auto x : a){
        if(sz(x) == 6){
            int cnt = 0;
            for(auto c : x){
                if(one_chars.count(c))cnt++;
            }
            if(cnt == 1)wa[x] = 6;
        }
    }
}

void find_nine(){
    map<char,int> four_chars;
    for(auto x: a){
        if(sz(x) == 4){
            for(auto c : x){
                four_chars[c]++;
            }
        }
    }

    for(auto x : a){
        if(sz(x) == 6){
            int cnt = 0;
            for(auto c : x){
                if(four_chars.count(c))cnt++;
            }
            if(cnt == 4)wa[x] = 9;
        }
    }
}
void find_zero(){
    for(auto x : a){
        if(sz(x) == 6 && !wa.count(x)){
            wa[x] = 0;
        }
    }
}

void find_three(){
    map<char,int> seven_chars;
    for(auto x: a){
        if(sz(x) == 3){
            for(auto c : x){
                seven_chars[c]++;
            }
        }
    }

    for(auto x : a){
        if(sz(x) == 5){
            int cnt = 0;
            for(auto c : x){
                if(seven_chars.count(c))cnt++;
            }
            if(cnt == 3)wa[x] = 3;
        }
    }
}

void find_five(){
    map<char,int> six_chars;
    for(auto x: a){
        if(wa.count(x) && wa[x] == 6){
            for(auto c : x){
                six_chars[c]++;
            }
        }
    }

    for(auto x : a){
        if(sz(x) == 5 && !wa.count(x)){
            int cnt = 0;
            for(auto c : x){
                if(six_chars.count(c))cnt++;
            }
            if(cnt == 5)wa[x] = 5;
        }
    }
}

void find_Two(){
    for(auto x : a){
        if(!wa.count(x))wa[x] = 2;
    }
}
void solve(int tc)
{
    // 1 : 2 character , 4 : 4 characters , 7 : 3 chars , 8 : 7
    int n;
    cin>>n;
    
    int ans = 0;
    for(int i = 0;i<n;i++){
        wa.clear();
        for(int j = 0;j<10;j++){
            cin>>a[j];
            sort(all(a[j]));
            if(sz(a[j]) == 2) wa[a[j]] = 1;
            if(sz(a[j]) == 4) wa[a[j]] = 4;
            if(sz(a[j]) == 3) wa[a[j]] = 7;
            if(sz(a[j]) == 7) wa[a[j]] = 8;
        }
        find_six();
        find_nine();
        find_zero();
        find_three();
        find_five();
        find_Two();
        

        int curr = 1000;
        
        for(int j = 0;j<4;j++){
            cin>>x;
            sort(all(x));
            ans+=(curr*wa[x]);
            curr/=10;
        }
    }
    cout<<ans<<endl;
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