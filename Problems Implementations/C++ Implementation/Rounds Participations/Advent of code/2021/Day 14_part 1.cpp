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

void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
}
int tc;
const int N = 1e6 + 5, M = 2e6 + 5, MOD = 1e9 + 7, OO = 1e9 + 7;
const ll INF = 2e18;
int n,m;


class Node
{

public:
    char c;
    Node *next;
    Node(char x){
        this->c = x;
        this->next = nullptr;
    }
};


void solve(int tc)
{
    string a;
    cin>>a;

    Node *head = new Node(a[0]);
    Node *curr = head;
    for(int i = 1;i<sz(a);i++){
        Node *newNode = new Node(a[i]);
        curr->next = newNode;
        curr = newNode;
    }
    
    string x;
    char b;
    map<string,char>wa;
    while(cin>>x>>b){
        wa[x] = b;
    }
    
for(int i = 0;i<10;i++){
        Node *curr = head;
        bool ignore = false;
        while(curr->next != nullptr){
            if(!ignore){
                x = "";
                x+= curr->c;
                x+= curr->next->c;
                if(wa.count(x)){
                    ignore = true;
                    Node *newNode = new Node(wa[x]);
                    newNode->next = curr->next;
                    curr->next = newNode;
                }
            }else{
                ignore = false;
            }
            curr = curr->next;
        }
    }

    map<char,int>occ;
    int mx = 0 , mn = 1000000000;
    curr = head;
    while(curr != nullptr){
        occ[curr->c]++;
        curr = curr->next;   
    }
    curr = head;
    while(curr != nullptr){
        mx = max(mx,occ[curr->c]);
        mn = min(mn,occ[curr->c]);
        curr = curr->next;
    }

    cout<<mx - mn <<endl;
    
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