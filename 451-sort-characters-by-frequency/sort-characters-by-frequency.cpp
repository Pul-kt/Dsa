class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans = "";

        unordered_map<char,int> freq;
        for (char ch : s) {
            freq[ch]++; 
        }

        priority_queue<pair<int,char>> pq;
        for(auto it : freq){
            pq.push({it.second,it.first});
        }

        while(!pq.empty()){
            int frequency = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(frequency > 0){
                ans.push_back(ch);
                frequency--;
            }
        }
        return ans;
    }
};