#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;

void solve(int tc){
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;

    int l = 0;
    int A = 0 , B = 0;
    int ans = 0;
    for(int r = 0;r<n;r++){
        A += (a[r] == 'a');
        B += (a[r] == 'b');
        while(A > k && B > k){
            A -= (a[l] == 'a');
            B -= (a[l] == 'b');
            l++;
        }

        ans = max(r-l+1,ans);
    } 

    cout<<ans<<endl;

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