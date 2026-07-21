class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> proj;
        for(int i=0;i<n;i++){
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        int i=0;
        priority_queue<int> pq;
        while(k--){
            while(i<n){
                if(proj[i].first>w){
                    break;
                }
                pq.push(proj[i].second);
                i++;
            }
            if(pq.empty()){
                return w;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};