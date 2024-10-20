class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int mm=0;
        int ans=0;
        while(l<k){
            mm+=nums[l];
            l++;
        }
        ans=mm;
        for(;l<nums.size();l++){
            mm-=nums[l-k];
            mm+=nums[l];
            ans=max(ans,mm);
        }
        return (double)ans/(double)k;
    }
};
