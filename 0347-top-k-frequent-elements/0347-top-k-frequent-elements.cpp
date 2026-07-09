class Solution {
public:
struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        for(auto i:f){
            pair<int,int> curr={i.second,i.first};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first<pq.top().first){
                continue;
            }
            pq.pop();
            pq.push(curr);
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};