class Solution {
  public:
    void reverseStack(stack<int>& st, int ele){
        if(st.empty()){
            st.push(ele); return;
        }
        int x = st.top(); st.pop();
        reverseStack(st, ele); st.push(x);
    }
    void reverse(stack<int> &st) {
        // code here
        if(!st.empty()){
            int ele = st.top(); st.pop();
            reverse(st); reverseStack(st, ele);
        }
    }
};
