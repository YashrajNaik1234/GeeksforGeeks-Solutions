class Solution {
  public:
    bool solve(Node* &root){
        if(!root) return true;
        if(!root -> left and !root -> right) return true;
        int leftSum = (root -> left) ? root -> left -> data : 0;
        int rightSum = (root -> right) ? root -> right -> data : 0;
        
        if(root -> data != leftSum + rightSum) return false;
        return solve(root -> left) and solve(root -> right);
    }
    int isSumProperty(Node *root) {
        // code here
        return solve(root);
    }
};
