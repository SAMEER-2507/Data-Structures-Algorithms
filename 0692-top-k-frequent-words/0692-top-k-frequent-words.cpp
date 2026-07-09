class Solution {
public:
struct cmp{
    bool operator()(pair<int,string>& a,pair<int,string>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        unordered_map<string,int> f;
        for(int i=0;i<words.size();i++){
            f[words[i]]++;
        }
        for(auto i:f){
            pair<int,string> curr={i.second,i.first};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if((curr.first>pq.top().first)||(curr.first==pq.top().first && curr.second<pq.top().second)){
                pq.pop();
                pq.push(curr);
            }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};