class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int l = 0,r = n-1;
        while(l<r){
            int sum = numbers[l] + numbers[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
        }
        return ans;
    }
};