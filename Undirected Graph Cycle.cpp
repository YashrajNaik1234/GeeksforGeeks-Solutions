class Solution {
  public:
    bool detect(int src, vector<vector<int>> adj, int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto i:adj[x]){
                if(!vis[i]){
                    vis[i] = 1; q.push({i, x});
                }
                else if(y != i) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        
        for(int i(0);i < edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        int vis[V] = {0};
        for(int i(0);i < V;i++){
            if(!vis[i]){
                if(detect(i, adjList, vis)) return true;
            }
        }
        
        return false;
    }
};
