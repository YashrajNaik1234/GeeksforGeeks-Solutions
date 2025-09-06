class Solution {
  public:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i] and dfs(i, adj, vis, pathVis)) return true;
            else if(pathVis[i]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        vector<int> adj[V];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i(0);i < V;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};
