class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)return nums;
        vector<int> ans(nums.size(),-1);
        if(nums.size()<=2*k){
            return ans;
        }
        int l=0,r=k-1;
        long tmp=0;
        while(l<r){
        tmp+=nums[l];
        l++;
        }
        while(r<2*k+1){
            tmp+=nums[r];
            r++;
        }
        ans[l+1]=tmp/(2*k+1);
        for(int i=k+1;i<nums.size()-k;i++){
            tmp-=nums[i-k-1];
            tmp+=nums[i+k];
            ans[i]=tmp/(2*k+1);
        }
        return ans;
    }
};
