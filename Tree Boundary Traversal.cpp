class Solution{
public:
    bool isLeaf(Node* root){
        if(!root->left and !root->right) return true;
        return false;
    }
    void addLeftBoundary(Node* root, vector<int>& ans){
        Node* cur = root -> left;
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur -> data);
            
            if(cur -> left) cur = cur -> left;
            else cur = cur -> right;
        }
    }
    void addRightBoundary(Node* root, vector<int>& ans){
        Node* cur = root -> right;
        vector<int> res;

        while(cur){
            if(!isLeaf(cur)) res.push_back(cur -> data);
            
            if(cur -> right) cur = cur -> right;
            else cur = cur -> left;
        }

        for(int i(res.size() - 1);i >= 0;i--) ans.push_back(res[i]);
    }
    void addLeaves(Node* root, vector<int>& ans){
        if(isLeaf(root)){
            ans.push_back(root -> data); return;
        }

        if(root -> left) addLeaves(root -> left, ans);
        if(root -> right) addLeaves(root -> right, ans);
    }
    vector <int> boundaryTraversal(Node* root){
    	//your code goes here
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root -> data);
        
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};
