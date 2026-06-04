class Solution {
  public:
  
    vector<int> dfshelp(vector<vector<int>>& adj, vector<int>& res, vector<bool>& vis, int node){
        res.push_back(node);
        vis[node] = true;
        for(int i=0;i<adj[node].size();i++){
            
            int neighbour = adj[node][i];

            if(vis[neighbour]==false){
                dfshelp(adj, res, vis, neighbour);
            }
        }
        
        return res;
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> res;
        vector<bool> vis(n,0);
        res = dfshelp(adj, res, vis, 0);
        return res;
    }
};