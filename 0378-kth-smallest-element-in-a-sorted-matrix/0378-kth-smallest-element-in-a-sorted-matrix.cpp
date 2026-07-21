class Solution {
public:
class node{
    public:
    int value;
    int row;
    int col;
    node(int v,int r,int c){
        value=v;
        row=r;
        col=c;
    }
};
struct cmp{
    bool operator()(const node& a,const node& b){
        return a.value>b.value;
    }
};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node,vector<node>,cmp> pq;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],i,0});
        }
        int res=0;
        while(k--){
            node curr=pq.top();
            pq.pop();
            res=curr.value;
            if(curr.col<n-1){
                pq.push({matrix[curr.row][curr.col+1],curr.row,curr.col+1});
            }
        }
        return res;
    }
};