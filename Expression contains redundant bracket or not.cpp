class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st; bool flag(true);
        
        for(int i(0);i < s.size();i++){
            if(!isalnum(s[i])) st.push(s[i]);
            if(s[i] == ')'){
                st.pop();
                while(st.top() != '('){
                    st.pop(); flag = false;
                }
                st.pop();
                if(flag) return true;
            }
            flag = true;
        }
        
        return false;
    }
};
