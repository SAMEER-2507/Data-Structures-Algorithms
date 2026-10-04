class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(i=m-1;i>=0;i--){
            for(j=n-1;j>=0;j--){
                if((i==m-1)&&(j==n-1)){
                    continue;
                }
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};