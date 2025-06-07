class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int it:arr){
            freq[it]++;
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }

        while(k--){
            auto temp = pq.top();
            pq.pop();
            int freq = temp[0];
            int val = temp[1];
            if(--freq) pq.push({freq,val});
        }
        return pq.size();
    }
};