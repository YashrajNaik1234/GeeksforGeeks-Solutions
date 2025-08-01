class Solution{
    public:
    bool solve(int i, int n, vector<int> &v, int sum, int k, bool &ans){
        if (sum == k){
            ans = 1; return 1;
        }
        if (i >= n) return 0;
        solve(i + 1, n, v, sum + v[i], k, ans);
        solve(i + 1, n, v, sum, k, ans);
        return ans;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
        bool ans = 0;
        solve(0, nums.size(), nums, 0, k, ans);
        return ans;
    }
};
