#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5+7;

void solve(int tc){
    int n;

    scanf("%d",&n);

    bool wa1 = false , wa2 = false;
    int mx = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        mx = max(mx,x);
        if(x == i)wa1=true;
        else wa2=true;

        if(i == mx){
            if(wa1 && wa2){
                ans = 2;
                continue;
            }
            else if(wa2){
                ans++;
                wa2 = false;
            }else if(wa1){
                wa1 = false;
            }
        }
    }
    
    printf("%d\n",min(ans,2) );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)
        solve(i);
}