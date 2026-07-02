class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1,high=*max_element(candies.begin(),candies.end()),res=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long cnt=0;
            for(int i=0;i<candies.size();i++){
                cnt+=candies[i]/mid;
            }
            if(cnt>=k){
                res=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return res;
    }
};