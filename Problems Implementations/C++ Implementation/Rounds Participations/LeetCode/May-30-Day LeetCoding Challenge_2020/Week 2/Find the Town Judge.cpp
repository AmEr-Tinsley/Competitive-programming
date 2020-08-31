class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        std::vector<set<int>> trusted(N+1);
        std::vector<bool>wa(N+1);

        for(auto p : trust){
        	trusted[p[1]].insert(p[0]);
        	wa[p[0]]=1;
        }
        int ret = -1;

        for(int i=1;i<=N;i++){
        	if(trusted[i].size()==N-1 && !wa[i]){
        		if(ret!=-1)return -1;
        		ret = i;
        	}
        }
        return ret;
    }
};