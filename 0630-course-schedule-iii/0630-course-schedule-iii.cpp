class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        if(n<=0){
            return 0;
        }
        for(int i=0;i<n;i++){
            swap(courses[i][0],courses[i][1]);
        }
        sort(courses.begin(),courses.end());
        priority_queue<int> pq;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=courses[i][1];
            pq.push(courses[i][1]);
            if(sum>courses[i][0]){
                sum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};