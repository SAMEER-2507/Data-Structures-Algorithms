class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0,high=citations.size()-1,answer=0;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(citations[mid]>=citations.size()-mid){
                answer=citations.size()-mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return answer;
    }
};