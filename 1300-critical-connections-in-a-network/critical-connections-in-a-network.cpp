class Solution {
public:
void dfs(int node,int parent,vector<vector<int>>& adj,
    vector<bool>& vis,vector<int>& disc,vector<int>& low,int count,vector<vector<int>>& ans){

    disc[node] = low[node] = count;
    vis[node] = 1;

    for(int j=0;j<adj[node].size();j++){
        int neigh = adj[node][j];
        if(neigh == parent) continue;
        else if(vis[neigh]) low[node] = min(low[node],low[neigh]);
        else{
            count++;
            dfs(neigh,node,adj,vis,disc,low,count,ans);
            //is bridge present or not
            if(low[neigh] > disc[node]){
                ans.push_back({neigh,node});
            }
            low[node] = min(low[node],low[neigh]);
        }
    }
}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;
        vector<int> disc(n,-1); //when did we discover this code so basically count
        vector<int> low(n); //lowest node the curr node can visit.
        vector<bool> vis(n,0);
        int count = 0;
        dfs(0,-1,adj,vis,disc,low,count,ans);
        return ans;
    }
};