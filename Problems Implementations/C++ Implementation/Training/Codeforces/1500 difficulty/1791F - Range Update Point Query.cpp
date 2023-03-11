#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define  ll long long

using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;

int n,q;
int seg[4*N];

void propagate(int indx){
    seg[indx*2] = seg[indx*2] + seg[indx];
    seg[indx*2+1] = seg[indx*2+1] + seg[indx];
    seg[indx] = 0;
}
void update(int indx,int l,int r,int i,int j){
    if(l >= i && r <= j){
        seg[indx]++;
        return;
    }

    if(l > j || r < i ){
        return;
    }
    propagate(indx);
    int mid = (l+r)/2;
    update(indx*2,l,mid,i,j);
    update(indx*2+1,mid + 1,r,i,j);
}

void resetPos(int indx,int l,int r,int pos){
    if(l == r){
        seg[indx] = 0;
        return;
    }
    propagate(indx);
    int mid = (l+r)/2;
    if(pos <= mid){
        resetPos(indx*2,l,mid,pos);
    }else{
        resetPos(indx*2+1,mid + 1,r,pos);
    }
}

int get(int indx,int l,int r,int pos){
    if(l == r){
        return seg[indx];
    }
    propagate(indx);
    int mid = (l+r)/2;
    if(pos <= mid)return get(indx*2,l,mid,pos);
    else return get(indx*2+1,mid+1,r,pos);
}

int getCount(int n){
    int ret = 0;
    while(n){
        ret += n%10;
        n /= 10;
    }
    return ret;
}
void solve(int tc){    
    scanf("%d %d",&n,&q);
    for(int i = 0;i<4*n;i++){
        seg[i] = 0;
    }
    std::vector<int> a(n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }

    while(q--){
        int type;
        scanf("%d",&type);
        if(type == 1){
            int l , r;
            scanf("%d %d",&l,&r);
            l--,r--;
            update(1,0,n-1,l,r);
        }else{
            int pos;
            scanf("%d",&pos);
            pos--;
            int cnt = get(1,0,n-1,pos);
            resetPos(1,0,n-1,pos);
            while(cnt-- && a[pos] >= 10){
                a[pos] = getCount(a[pos]);
            }
            printf("%d\n",a[pos] );
        }
    }
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