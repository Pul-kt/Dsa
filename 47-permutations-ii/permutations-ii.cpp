class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& used, vector<int>& curr,
               vector<vector<int>>& result) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size();i++) {
            // Skip the duplicate elements
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            curr.push_back(nums[i]);
            solve(nums, used, curr, result);
            used[i] = false;
            curr.pop_back();
        }
    }
        vector<vector<int>> permuteUnique(vector<int> & nums) {
            vector<vector<int>> result;
            vector<int> curr;
            vector<bool> used(nums.size(), false);
            sort(nums.begin(),nums.end());
            solve(nums, used, curr, result);
            return result;
        }
    };
