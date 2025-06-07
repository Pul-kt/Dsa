class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        
        int ans = 1e9;
        while(k--){
            auto temp = pq.top();
            pq.pop();

            int value = temp[0];
            int row = temp[1];int col = temp[2];
            ans = value;

            if(col+1 < n) pq.push({matrix[row][col+1],row,col+1});
            
        }
        return ans;

    }
};