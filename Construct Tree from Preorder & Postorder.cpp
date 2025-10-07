class Solution {
  public:
    Node *build(vector<int>& pre, vector<int>& post, int &preIndex, int start, int end, int n){
        Node* root = new Node(pre[preIndex]); preIndex++;

        if (start == end || preIndex >= n) return root;

        int leftChild = pre[preIndex];
        int pos = start;

        while (pos <= end && post[pos] != leftChild)
            pos++;

        if (pos <= end) {
            root -> left = build(pre, post, preIndex, start, pos, n);
            root -> right = build(pre, post, preIndex, pos + 1, end, n);
        }

        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int n = pre.size(), preIndex = 0;
        return build(pre, post, preIndex, 0, n - 1, n);
    }
};
