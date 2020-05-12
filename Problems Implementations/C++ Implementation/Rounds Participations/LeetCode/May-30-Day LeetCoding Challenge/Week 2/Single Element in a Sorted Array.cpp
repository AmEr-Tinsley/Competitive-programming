class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ,  r = n-1 , ret;

        while(l<=r){
        	int mid = (l+r)/2;

        	if(mid%2){
        		if(nums[mid]!=nums[mid-1]){
        			r = mid - 1;
        			ret = mid ;
        		}
        		else	l = mid+1;
        	}
        	else{
        		if(mid+1 == n){
        			return nums[mid];
        		}
        		if(nums[mid]!=nums[mid+1]){
        			r = mid-1;
        			ret = mid;
        		}
        		else	l = mid+1;
        	}
        }
        return nums[ret];
    }
};
