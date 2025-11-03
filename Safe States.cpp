class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(V, 0);
        
        for (auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        
        for (int i(0); i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            ans.push_back(u); q.pop();
            
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        
        return ans;
    }
};
