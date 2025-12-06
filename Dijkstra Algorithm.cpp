class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[n + 1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0; pq.push({0, src});
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int node = it.second, dis = it.first;
            
            if(dis > dist[node]) continue;
            for(auto x:adj[node]){
                int adjNode = x.first; int edW = x.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
