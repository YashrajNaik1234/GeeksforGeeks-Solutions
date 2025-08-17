class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* suc = nullptr;
        Node* pre = nullptr;
        Node* head = root;
        
        while(root){
            if(key >= root -> data){
                root = root -> right;
            }
            else{
                suc = root;
                root = root -> left;
            }
        }
        
        root = head;
        
        while(root){
            if(key <= root -> data){
                root = root -> left;
            }
            else{
                pre = root;
                root = root -> right;
            }
        }
        
        return {pre, suc};
    }
};
