class Solution {
  public:
    void solve(Node* root, vector<int>& ans){
        if(!root) return;
        solve(root -> left, ans);
        solve(root -> right, ans);
        ans.push_back(root -> data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
