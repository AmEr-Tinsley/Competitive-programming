//
//  main.cpp
//  CP
//
//  Created by Ameur Hosni on 10/02/2023.
//

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
  // insert code here...
  int n;
  
  scanf("%d",&n);
  
  multiset<int>s;
  long long curr = 0;
  int ans = n;
  for(int i = 0;i<n;i++){
    int x;
    scanf("%d",&x);
    s.insert(x);
    curr += x;

    if(curr < 0){
      auto it = s.begin();
      curr -= *it;
      s.erase(it);
      ans--;
    }
  }

  printf("%d\n",ans);
  return 0;
}
