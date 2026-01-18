class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        stack<int> st;
        map<int, int> mp;
        vector<int> ans(arr.size(), -1);
        
        for(auto x: arr) mp[x]++;
        st.push(arr.back());
        
        for(int i(arr.size() - 2);i >= 0; i--) {
            while(!st.empty() && mp[st.top()] <= mp[arr[i]]) st.pop();
            
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};
