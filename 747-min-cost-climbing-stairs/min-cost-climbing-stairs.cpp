class Solution {
    int f(int n,vector<int>& cost,vector<int>& dp){
        //base case 
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = cost[n] + min(f(n-1,cost,dp),f(n-2,cost,dp));
        return dp[n];
     }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        int ans = min(f(n-1,cost,dp),f(n-2,cost,dp));
        return ans;
    }
};