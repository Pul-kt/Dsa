class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> soldiers(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 1) soldiers[i]++;
            }
        }

        priority_queue<pair<int,int>> pq;
        for(int i = 0;i < soldiers.size();i++){
            if(pq.size() < k) pq.push({soldiers[i],i});
            else if(pq.top().first > soldiers[i]){
                pq.pop();
                pq.push({soldiers[i],i});
            }
        }

        vector<int>ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};