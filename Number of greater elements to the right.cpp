
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        vector<int> count(arr.size()); 
        stack<int> st,en;
        
        for(int i(arr.size() - 1);i >= 0;i--){
            while(!st.empty() and arr[i] >= st.top()){
                en.push(st.top()); st.pop();
            }
            
            count[i] = st.size();
            st.push(arr[i]);
            
            while(!en.empty()){
                st.push(en.top()); en.pop();
            }
        }
        
        vector<int> ans;
        for(int i(0);i < indices.size();i++) ans.push_back(count[indices[i]]);
        return ans;
    }
};
