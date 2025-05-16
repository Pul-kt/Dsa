class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int l = i + 1; l < n; l++) {
                if (l > i + 1 && nums[l] == nums[l - 1])
                    continue;
                // else
                int j = l + 1;
                int k = n - 1;
                while (j < k) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[l], nums[j], nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                    else if (sum > target) {
                            k--;
                    }
                    else {
                            j++;
                    }
                }
            }
        }
        return ans;
        }
    };