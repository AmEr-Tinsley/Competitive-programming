class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int all = 0 , curr = 0 , ret = 0;
        for(int i = 0;i<n;i++){
        	int gain = gas[i] - cost[i];
        	curr+=gain;
        	all+=gain;
        	if(curr<0){
        		curr  = 0;
        		ret = i + 1;
        	}
        }
        return all >= 0 ? ret : -1;
    }
};