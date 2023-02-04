#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5005;

ll memo[5005][5005];
set<int>s;
int a[5005],c[5005];
int n,m;
int seg[4*N];
void build(int indx,int l,int r){
    if(l == r){
        seg[indx] = c[l];
        return;
    }

    build(indx * 2,l,(l+r)/2);
    build(indx*2+1,(l+r)/2+1,r);

    seg[indx] = min(seg[indx*2],seg[indx*2+1]);
}

int get(int indx,int l,int r,int i,int j){
    if(l>j || r <i){
        return 1e9;
    }

    if(l >= i && r <= j)return seg[indx];

    int left = get(indx*2,l,(l+r)/2,i,j);
    int right = get(indx*2+1,(l+r)/2+1,r,i,j);
    
    return min(left,right);
}
ll solve(int indx,int taken){
    if(indx == n){
        return 0;
    }

    ll &ret = memo[indx][taken];

    if(~ret)return ret;

    if(s.count(indx)){
        int who = get(1,0,n-1,indx-taken,indx);
        return ret = solve(indx+1,taken+1) + (ll)a[indx] + who;
    }

    ret = solve(indx+1,taken);
    int who = get(1,0,n-1,indx-taken,indx);
    return ret = min(solve(indx+1,taken+1) + (ll)a[indx] + who,ret);
}

void solve(int tc){
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<n;i++){
        scanf("%d",&c[i]);
    }

    build(1,0,n-1);

    for(int i = 0,x;i<m;i++){
        scanf("%d",&x);
        x--;
        s.insert(x);
    }

    memset(memo,-1,sizeof(memo));

    printf("%lld\n",solve(0,0));
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