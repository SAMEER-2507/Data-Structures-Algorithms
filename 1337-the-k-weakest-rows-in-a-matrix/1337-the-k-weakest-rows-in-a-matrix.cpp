class Solution {
public:
struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i=0;i<mat.size();i++){
            int low=0,high=mat[0].size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(mat[i][mid]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            pair<int,int> curr={low+1,i};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if((curr.first<pq.top().first)||(curr.first==pq.top().first && curr.second<pq.top().second)){
                pq.pop();
                pq.push(curr);
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};