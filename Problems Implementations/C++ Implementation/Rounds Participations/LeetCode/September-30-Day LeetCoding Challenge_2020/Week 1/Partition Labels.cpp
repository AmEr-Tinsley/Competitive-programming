class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> lastpos(26);
        for(int i = 0;i<S.size();i++){
        	lastpos[S[i]-'a'] = i;
        }
        int curr = 0 , mx = 0;
        std::vector<int> ret;
        for(int i = 0;i<S.size();i++){
        	curr++;
        	mx = max(mx,lastpos[S[i]-'a']);
        	if(mx == i){
        		ret.push_back(curr);
        		mx = i+1;
        		curr = 0;
        	}
        }
        return ret;
    }
};