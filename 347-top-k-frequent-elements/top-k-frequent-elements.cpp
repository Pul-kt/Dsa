class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int it : nums){
            freq[it]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        while(k>0){
            auto temp = pq.top();
            pq.pop();
            k--;
            int val = temp.second;
            ans.push_back(val);
        }
        return ans;
    }
};