class Solution {
  public:
    int sum = 0;
    void transformTree(Node *root) {
        // code here
        if(!root) return;
        
        int x = root -> data;
        transformTree(root -> right);
        root -> data = sum; sum += x;
        transformTree(root -> left);
    }
};
