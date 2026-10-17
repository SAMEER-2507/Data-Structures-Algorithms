class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> c;
        c.push_back(0);
        for(int i=0;i<cuts.size();i++){
            c.push_back(cuts[i]);
        }
        c.push_back(n);
        sort(c.begin(),c.end());
        int m=c.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i=m-2;i>=1;i--){
            for(int j=i;j<=m-2;j++){
                int res=INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost=c[j+1]-c[i-1];
                    int r=cost+dp[i][k-1]+dp[k+1][j];
                    res=min(res,r);
                }
                dp[i][j]=res;
            }
        }
        return dp[1][m-2];
    }
};