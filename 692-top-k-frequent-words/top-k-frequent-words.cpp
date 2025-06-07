class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (auto& it:words) {
            freq[it]++;
        }
        auto cmp = [](pair<int,string>& a,pair<int,string>& b) {
            if (a.first == b.first) return a.second > b.second;  
            // Lex smaller comes first
            return a.first < b.first;  // Higher freq comes first
        };

        priority_queue<pair<int,string>,vector<pair<int,string>>,
            decltype(cmp)>pq(cmp);

        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        while (k-- > 0) {
            string temp = pq.top().second;
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};