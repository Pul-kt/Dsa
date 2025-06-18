class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;
            //right part sorted
            if(nums[mid] < nums[high]){
                if(target > nums[mid] && target <= nums[high]) low = mid+1;
                else high = mid;
            }
            //left part sorted
            else{
                if(target < nums[mid] && target >= nums[low]) high = mid;
                else low = mid+1;
            }
        }
        return -1;
    }
};