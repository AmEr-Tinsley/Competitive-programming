#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5+7;

int n;
string a;

int go(char c,int l,int r){
    if(l == r)return (a[l] != c);
    int mid = (l+r)/2;
    int ret = n;
    int cnt = 0;

    for(int i = l;i<=mid;i++)cnt+=int(a[i] != c);

    ret = cnt + go(++c,mid+1,r);
    --c;
    cnt = 0;
    for(int i = mid+1;i<=r;i++)cnt+=int(a[i] != c);
    return min(ret,cnt+go(++c,l,mid));
}

void solve(int tc){
    cin>>n>>a;
    cout<<go('a',0,n-1)<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin>>tc;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}