#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

void solve(int tc){
    string a;
    cin>>a;
    set<int> ab,ba;
    int n = sz(a);
    for(int i = 0;i<n-1;i++){
        string curr = "";
        curr+=a[i];
        curr+=a[i+1];
        if(curr == "AB"){
            ab.insert(i);
        }else if(curr == "BA"){
            ba.insert(i);
        }
    }

    if(!sz(ab) || !sz(ba)){
        puts("NO\n");
        return;
    }

    for(auto x : ab){
        for(auto y : ba){
            if(abs(x-y) != 1){
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}