class Solution {
  public:
    int sum = 0;
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(!root) return sum;
        
        nodeSum(root -> left, l, r);
        if(root -> data >= l and root -> data <= r) sum += root -> data;
        nodeSum(root -> right, l , r);
        
        return sum;
    }
};
