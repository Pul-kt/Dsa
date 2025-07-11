class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int s = 0,e = 1;
        while(e<n){
            if(nums[s] == nums[e]) e++;
            else{
                nums[s+1] = nums[e];
                s++;
            }
        }
        return s+1;
    }
};