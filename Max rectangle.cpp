class Solution {
  public:
    vector<int> psefun(vector<int>& prefixsum){
        int n = prefixsum.size();
        vector<int> res(n);
        stack<int> st;
        
        for(int i(0);i < n;i++){
            while(!st.empty() && prefixsum[st.top()] >= prefixsum[i]) st.pop();

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        return res;
    }

    vector<int> nsefun(vector<int>& prefixsum){
        int n = prefixsum.size();
        vector<int> res(n);
        stack<int> st; 

        for(int i(n - 1);i >= 0;i--){
            while(!st.empty() && prefixsum[st.top()] >= prefixsum[i]) st.pop();

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    
    int hist(vector<int>& prefixsum){
        vector<int>nse = nsefun(prefixsum);
        vector<int>pse = psefun(prefixsum);
        int maxi = INT_MIN;
        int n = prefixsum.size();
        
        for(int i(0);i < n;i++){
            maxi = max(maxi , prefixsum[i] * (nse[i] - pse[i] - 1));
        }
        
        return maxi;
    }
    
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int ans = max(0, hist(mat[0]));
        
        for(int i(1);i < mat.size();i++){
            for(int j(0);j < mat[i].size();j++){
                if(mat[i][j] == 0) mat[i][j] = 0;
                else mat[i][j] += mat[i - 1][j];
            }
            ans = max(ans, hist(mat[i]));
        }
        
        return ans;
        
    }
};
