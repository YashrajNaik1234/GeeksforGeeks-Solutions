// User function Template for C++

class Solution {
  public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, string& x){
        queue<pair<int,int>> q; int n = grid.size(), m = grid[0].size();
        q.push({i ,j}); vis[i][j] = 1;
        
        while(!q.empty()){
            int z1 = q.front().first, z2 = q.front().second; q.pop();
            
            vector<char> v = {'D','U','L','R'};
            vector<int> x1 = {1, -1, 0, 0};
            vector<int> y1 = {0, 0, -1, 1};
            for(int s = 0; s < 4;s++){
                int xRow = z1 + x1[s], yCol = z2 + y1[s]; 
                char c = v[s];
                if(xRow >= 0 and xRow < n and yCol >= 0 and yCol < m
                    and grid[xRow][yCol] == 1 and !vis[xRow][yCol]){
                        vis[xRow][yCol] = 1; q.push({xRow, yCol}); x += c;
                    }
            }
            x += 'B';
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int cnt(0); set<string> s;
        for(int i(0);i < n;i++){
            for(int j(0);j < m;j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    string x = "";
                    bfs(grid, vis, i, j, x);
                    s.insert(x);
                }
            }
        }
        
        return s.size();
    }
};
