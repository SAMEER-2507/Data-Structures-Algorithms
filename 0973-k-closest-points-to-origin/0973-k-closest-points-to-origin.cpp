class Solution {
public:
struct cmp{
    bool operator()(pair<double,int>& a,pair<double,int>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,cmp> pq;
        unordered_map<int,double> f;
        for(int i=0;i<points.size();i++){
            f[i]=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
        }
        for(auto i:f){
            pair<double,int> curr={i.second,i.first};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first>pq.top().first){
                continue;
            }
            pq.pop();
            pq.push(curr);
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};