class Solution {
  public:
    void solve(int n, int i, string s, vector<string>& ans){
        if(i == n){
            ans.push_back(s); return;
        }

        solve(n, i + 1, s += "0", ans);
        s.pop_back();
        
        if(s[i - 1] != '1') solve(n, i + 1, s += "1", ans);
        s.pop_back();
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        solve(num, 0, "", ans);
        return ans;
    }
};
