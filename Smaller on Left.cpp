class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size());
        
        for(int i(0);i < arr.size();i++){
            while(!st.empty() and arr[i] <= st.top()) st.pop();
            ans[i] = st.empty() ? -1 : st.top(); st.push(arr[i]);
        }
        
        return ans;
    }
};
