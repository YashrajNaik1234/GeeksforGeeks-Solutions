class Solution{
public:
    void markParent(Node* root, unordered_map<Node*,Node*>& mp){
        queue<Node*> q; q.push(root);
        while(!q.empty()){
            Node* cur = q.front(); q.pop();

            if(cur -> left){
                mp[cur -> left] = cur;
                q.push(cur -> left);
            }

            if(cur -> right){
                mp[cur -> right] = cur;
                q.push(cur -> right);
            }
        }
    }

    Node* findTarget(Node* root, int target){
        if(!root) return root;
        if(root -> data == target) return root;

        Node* temp = findTarget(root -> left, target);
        if(temp != nullptr) return temp;
        return findTarget(root -> right, target);
    }

    int maxDist(Node *tar, unordered_map<Node *, Node *> mp, unordered_map<Node *, bool> vis, queue<Node*> q){
        int cur = 0;
        while(!q.empty()){
            int size = q.size(); bool burned = false;
            for(int i(0);i < size;i++){
                auto x = q.front(); q.pop();

                if(x -> left and (!vis[x -> left] or vis.find(x -> left) == vis.end())){
                    q.push(x -> left); vis[x -> left] = true; burned = true;
                }

                if (x->right and (!vis[x->right] or vis.find(x->right) == vis.end()))
                    {
                        q.push(x->right);
                        vis[x->right] = true;
                        burned = true;
                    }

                if(mp[x] and (!vis[mp[x]] or vis.find(mp[x]) == vis.end())){
                    q.push(mp[x]); vis[mp[x]] = true; burned = true;
                }
            }
            if(burned) cur++;
        }

        return cur;
    }

        int minTime(Node *root, int target)
    {
        // code here
        unordered_map<Node *, Node *> mp;
        markParent(root, mp);

        Node* x = findTarget(root, target);
        unordered_map<Node *, bool> vis;
        queue<Node *> q; q.push(x); vis[x] = true;
        return maxDist(x, mp, vis, q);
    }
};
