class Solution {
  public:
    bool isSafe(int node, int v, int col, vector<int>&color, vector<vector<int>>& adj){
        for(auto it : adj[node]){
            if(color[it] == col) return false;
        }
        
        return true;
    }
     bool solve(int node, int v, int m, vector<int>&color, vector<vector<int>>& adj){
        // Base Case.
        if(node == v) return true;
        
        for(int i = 1; i <= m; i++){
            if(isSafe(node, v, i, color, adj)){
                color[node] = i;
                if(solve(node + 1, v, m, color, adj)) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        
        for(auto it : edges){
            int v1 = it[0];
            int v2 = it[1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        
        vector<int>color(v, 0);
        
        bool ans = solve(0, v, m, color, adj);
        return ans;
    }
};
