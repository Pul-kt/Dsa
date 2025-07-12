class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int index = n-1;
        int l = 0,r = n-1;
        while(l<=r){
            if(abs(nums[l]) > abs(nums[r])){
                nums[l] = nums[l]*nums[l];
                ans[index--] = nums[l]; 
                l++;
            }
            else{
                nums[r] = nums[r]*nums[r];
                ans[index--] = nums[r];
                r--;
            }
        }
        return ans;
    }
};