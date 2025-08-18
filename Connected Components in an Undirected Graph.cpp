class Solution {
  public:
    vector<vector<int>> adj;
    void dfs(int i, vector<bool> &vis, vector<int>& temp) {
        vis[i] = true;
        temp.push_back(i);
        for (auto j : adj[i])
            if (!vis[j]) dfs(j, vis, temp);
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool> vis(V, 0);
        adj.resize(V);
        vector<vector<int>> ans;

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for (int i(0); i < V; i++) {
            if (!vis[i]) {
                vector<int> temp;
                dfs(i, vis, temp);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
