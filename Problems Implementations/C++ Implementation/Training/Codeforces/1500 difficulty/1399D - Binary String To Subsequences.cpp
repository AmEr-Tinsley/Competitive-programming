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
    string a;
    cin>>n>>a;
    
    set<int>s1,s2;

    for(int i = 0;i<n;i++){
        if(a[i] == '0')s1.insert(i);
        else s2.insert(i);
    }

    int curr = 0;
    vector<int>ans(n);

    for(int i = 0;i<n;i++){
        if(ans[i])continue;
        curr++;
        ans[i] = curr;
        bool wa = (a[i] == '1');
        int indx = i;
        while(1){
            ans[indx] = curr;
            auto it = wa ? s1.lower_bound(indx) : s2.lower_bound(indx);
            if(it == (wa ? s1.end() : s2.end())){
                break;
            }
            indx = *it;
            if(wa)s1.erase(it);
            else s2.erase(it);
            wa = !wa;
        }
    }

    cout<<curr<<endl;
    for(auto x : ans)cout<<x<<" ";
    cout<<"\n";
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