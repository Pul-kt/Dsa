class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto it : freq){
            pq.push({it.second,it.first});
        }

        string ans = "";
        while(!pq.empty()){
            int n = ans.length() - 1;
            bool poped = false;
            int tempFreq,tempCh;
            if(n >= 0 && ans[n] == pq.top().second) {
                if(pq.size() == 1) return "";
                tempFreq = pq.top().first;
                tempCh = pq.top().second; 
                pq.pop();
                poped = true;
            }

            int frequency = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans.push_back(ch);
            if(--frequency > 0) pq.push({frequency,ch});

            if(poped) pq.push({tempFreq,tempCh});
        }
        if(ans.length() == s.length()) return ans;
        return "";
    }
};