class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = 1e9;
        while(low <= high){
        int mid = low + (high-low)/2;
            //left half sorted
            if(nums[mid] >= nums[low]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            //right half is sorted
            else{
                ans = min(ans,nums[mid]);
                high = mid;
            }
       }
       return ans; 
    }
};