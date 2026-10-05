class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        int i,j;
        for(i=n-1;i>=0;i--){
            for(j=1;j<3;j++){
                if(j==1){
                    dp[i][j]=max(dp[i+1][2]+prices[i],dp[i+1][j]);
                }else{
                    dp[i][j]=max(dp[i+1][j-1]-prices[i],dp[i+1][j]);
                }
            }
        }
        return dp[0][2];
    }
};