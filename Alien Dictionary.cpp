class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        map<char,int> mp;
        for(auto i:words){
            for(auto j:i) mp[j]++;
        }
        
        vector<bool> present(26, false);
        vector<int> adj[26];
        vector<int> indegree(26,0);
        for(int i(0);i < words.size() - 1;i++){
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
            if (s1.size() > s2.size() && s1.find(s2) == 0) return "";
            for(int j(0);j < len;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a'); break;
                }
            }
        }
        
        for(auto &m : words){
            for(auto it : m) present[it-'a'] = true;
        }
        queue<int> q;
        for(int i(0); i < 26; i++){
            for(auto it: adj[i]) indegree[it]++;
        }
      
        for(int i(0); i < 26; i++){
            if(present[i] && indegree[i]==0) q.push(i);
        }
        
        string ans ="";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += node + 'a';
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        for(int i(0); i < 26; i++){
           if(indegree[i] != 0) return "";
        }
        return ans;
    }
};
