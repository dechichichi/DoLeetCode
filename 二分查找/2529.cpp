class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>0)r=mid-1;
            else l=mid+1;
        }
        int tag1=nums.size()-l;
        l=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=0)r=mid-1;
            else l=mid+1;
        }
        int tag2=l;
        return max(tag1,tag2);
    }
};
