#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9;
bool decToOctal(int n)
{
     
    // array to store octal number
    int octalNum[100];
 
    // counter for octal number array
    int i = 0;
    while (n != 0) {
 
        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
 
    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        if(octalNum[j] == 7)return true;
    return false;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		string wa = to_string(i);
		bool add = decToOctal(i);
		while(sz(wa)){
			add|=(wa.back()=='7');
			wa.pop_back();
		}
		if(add) ans++;

	}
	printf("%d\n",n-ans );
}