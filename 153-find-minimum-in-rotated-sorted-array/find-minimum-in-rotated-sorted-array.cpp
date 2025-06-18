class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1;

        while(low < high){

        int mid = low+(high-low)/2;
            //left half sorted
            //compare mid with high and not low as mid can be 0 also.
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            //right half is sorted
            else{
                high = mid;
            }
       }
       return nums[low]; 
    }
};