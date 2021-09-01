class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        int j = i - 1;
        std::vector<int> result;

        while(k--){
        	if(i  == arr.size()){
        		result.push_back(arr[j--]);
        		continue;
        	}
        	if(j == -1){
        		result.push_back(arr[i++]);
        		continue;
        	}

        	if(abs(arr[i]-x) < abs(arr[j]-x))result.push_back(arr[i++]);
        	else result.push_back(arr[j--]);
        }

        sort(result.begin(),result.end());
        return result;
    }
};