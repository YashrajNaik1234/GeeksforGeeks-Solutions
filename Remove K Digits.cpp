class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        if(k == s.size()) return "0";
        
        stack<char> st;
        for(int i(0);i < s.size();i++){
            while(!st.empty() and k and s[i] < st.top()){
                st.pop(); k--;
            }
            st.push(s[i]);
        }
        
        while(!st.empty() and k){
            st.pop(); k--;
        }
        
        string res = "";
        while(!st.empty()){
            res.push_back(st.top()); st.pop();
        }
        while(res.size() > 1 and res.back() == '0') res.pop_back();
        
        reverse(res.begin(), res.end());
        return res;
    }
};
