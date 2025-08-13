class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int sum(0),ans(INT_MIN);
        for(int i(0);i < arr.size();i++){
            sum += arr[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        
        return ans;
    }
};
