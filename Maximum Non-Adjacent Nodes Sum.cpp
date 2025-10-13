class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(!root) return {0, 0};
        
        auto l = solve(root -> left);
        auto r = solve(root -> right);
        
        int left = root -> data + l.second + r.second;
        int right = max(l.first, l.second) + max(r.first, r.second);
        
        return {left, right};
    }
    int getMaxSum(Node *root) {
        // code here
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
