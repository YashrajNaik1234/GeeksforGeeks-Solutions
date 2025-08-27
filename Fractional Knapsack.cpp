
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,pair<int,int>>> mp;
        for(int i(0);i < val.size();i++){
            mp.push_back({(double)(1.0 * val[i] / wt[i]), {val[i], wt[i]}});
        }

        sort(mp.rbegin(),mp.rend());

        double ans(0.000000); int j(0);
        while(j < mp.size() and capacity > 0){
            if(mp[j].second.second <= capacity){
                capacity -= mp[j].second.second;
                ans += mp[j].second.first;
            }
            else{
                ans += mp[j].first * capacity; capacity = 0;
            } j++;
        }
        
        return ans;
    }
};
