class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int it:gifts){
            pq.push(it);
        }

        while(k-- > 0){
            int temp = pq.top();
            pq.pop();
            int val = floor(sqrt(temp));
            if(val > 0) pq.push(val);
        }
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};