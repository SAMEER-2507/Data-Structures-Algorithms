class Solution {
public:
void dfs(vector<vector<int>>& isConnected,int city,vector<bool>& vis){
    vis[city]=true;
    for(int i=0;i<isConnected.size();i++){
        if(isConnected[city][i]&&!vis[i]){
            dfs(isConnected,i,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0,n=isConnected.size();
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,i,vis);
                res++;
            }
        }
        return res;
    }
};