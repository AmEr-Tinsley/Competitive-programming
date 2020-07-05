class Solution {
public:
    int nthUglyNumber(int n) {
     	std::vector<int> v(3);	
     	std::vector<int> curr;
     	curr.push_back(1);
     	for(int i= 1 ;i<n;i++){
     		if(curr[v[0]]*2<min(curr[v[1]]*3,curr[v[2]]*5)){
     			curr.push_back(curr[v[0]++]*2);
     		}
     		else if(curr[v[1]]*3<min(curr[v[0]]*2,curr[v[2]]*5)){
     			curr.push_back(curr[v[1]++]*3);
     		}
     		else{
     			curr.push_back(curr[v[2]++]*5);
     		}
     		if(curr[curr.size()-1] == curr[curr.size()-2]){
     			curr.pop_back();
     			i = i-1;
     		}
     	}
     	return curr.back();
     	
    }
};