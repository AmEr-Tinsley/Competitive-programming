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

    vector<int>a(n);
    vector<int>seen(n+1);
    vector<bool>processed(n+1);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        seen[a[i]]++;
    }

    int ans = 0;

    for(int i = 0;i<n;i++){
        int curr = a[i];
        for(int j = i+1;j<n;j++){            
            curr += a[j];
            if(curr > n)break;
            if(processed[curr])continue;
            processed[curr] = true;
            ans += seen[curr];
        }

    }
    printf("%d\n",ans );
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