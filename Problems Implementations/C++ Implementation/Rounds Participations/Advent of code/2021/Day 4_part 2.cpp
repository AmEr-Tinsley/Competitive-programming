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

void file(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt", "r", stdin);
	    //freopen("out.txt","w",stdout);
	#endif
}

int tc;
const int N = 1e6 + 5, M = 2e6 + 5, MOD = 1e9 + 7, OO = 1e9 + 7;
const ll INF = 2e18;
map<int,bool>drawn;

int count_score(vector<vector<int>>&a,int curr){
	int others = 0;
	for(int i = 0;i<5;i++){
		for(int j=0;j<5;j++){
			if(!drawn.count(a[i][j])){
				others+=a[i][j];
			}
		}
	}

	return curr*others;
}
int get_score(vector<vector<int>>&a,int curr){
	bool win = false;
	for(int i = 0;i<5;i++){
		int cnt = 0;
		for(int	j=0;j<5;j++){
			if(drawn.count(a[i][j])){
				cnt++;
			}
		}
		if(cnt == 5){
			win = true;
		}
	}
	for(int j = 0;j<5;j++){
		int cnt = 0;
		for(int i = 0;i<5;i++){
			if(drawn.count(a[i][j])){
				cnt++;
			}
		}
		if(cnt == 5){
			win = true;
		}
	}
	if(!win)return -1;
	return count_score(a,curr);
}
void solve(int tc){
    int n,m;

    scanf("%d",&n);
    std::vector<int> a(n);
    for(int i = 0,x;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
	vector<vector<vector<int>>> cards(m,vector<vector<int>>(5,vector<int>(5)));
	for(int i = 0 ;i<m;i++){
		for(int j =0;j<5;j++){
			for(int k = 0;k<5;k++){
				scanf("%d",&cards[i][j][k]);
			}
		}
	}
	int ans = 0;
	map<int,bool>already_won;
	for(int i = 0;i<n;i++){
		drawn[a[i]] = true;
		for(int j = 0;j<m;j++){
			if(already_won.count(j))continue;
			int score = get_score(cards[j],a[i]);
			if(score>=0){
				already_won[j] = true;
				ans = score;
			}
		}
	}
	printf("%d\n",ans );
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