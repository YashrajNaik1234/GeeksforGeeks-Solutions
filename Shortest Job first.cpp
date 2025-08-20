class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long ans(0),cnt(0);
        sort(bt.begin(),bt.end());
        
        for(int i(0);i < bt.size() - 1;i++){
            cnt += bt[i]; ans += cnt;
        }
        
        return ans / bt.size();
    }
};
