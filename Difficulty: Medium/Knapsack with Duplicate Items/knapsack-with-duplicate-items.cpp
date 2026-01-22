class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        vector<vector<int>> dp(val.size()+1,vector<int>(W+1,0));
        
        
        for(int i=1;i<=val.size();i++){
            for(int j = 1;j<=W;j++){
                // current balls are less then balls a batter required
                if(j<wt[i-1])
                dp[i][j] = dp[i-1][j];
                // if there are required number of balls -> compare the previous state value and new value
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-wt[i-1]] + val[i-1]);
            }
        }
        
        return dp[val.size()][W];
    }
};