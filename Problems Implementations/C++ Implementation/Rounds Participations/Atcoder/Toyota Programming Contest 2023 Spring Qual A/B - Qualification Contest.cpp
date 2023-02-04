#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+6;

void solve(int tc){
    int n,k;
    cin>>n>>k;
    vector<string>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.begin()+k);
    for(int i = 0;i<k;i++){
        cout<<a[i]<<"\n";
    }
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