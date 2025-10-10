class Solution {
  public:
    int solve(Node* root, int& ans){
        if(!root) return 0;
        
        int left = solve(root -> left, ans);
        int right = solve(root -> right, ans);
        
        ans = max({ans, root -> data + max({0, left, right}), root -> data + left + right});
        return root -> data + max({0, left, right});
    }
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
