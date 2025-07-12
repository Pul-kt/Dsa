class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0,r = 0;
        while(r<nums.size()){
            if(nums[r] != 0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
    }
};
//left stores the index till which we have non 0 elemets.