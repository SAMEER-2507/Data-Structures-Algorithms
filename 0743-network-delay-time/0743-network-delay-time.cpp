class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<times.size();i++){
            int s=times[i][0];
            int d=times[i][1];
            int w=times[i][2];
            a[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int d=p.first;
            int node=p.second;
            if(d>dist[node]){
                continue;
            }
            for(int i=0;i<a[node].size();i++){
                int neigh=a[node][i].first;
                int wt=a[node][i].second;
                if(d+wt<dist[neigh]){
                    dist[neigh]=wt+d;
                    pq.push({d+wt,neigh});
                }
            }
        }
        int res=*max_element(dist.begin(),dist.end());
        return res==INT_MAX?-1:res;
    }
};