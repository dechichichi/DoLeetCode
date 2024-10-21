class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int tag=0;
        long long ans=0;
        long long tmp=0;
        map<int,int>mp;
        for(int i=0;i<k;i++){
            tmp+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1)tag++;
            else if(mp[nums[i]]==2)tag--;
        }
        if(tag==k)ans=tmp;
        for(int i=k;i<nums.size();i++){
            tmp+=nums[i]-nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==1)tag++;
            else if(mp[nums[i-k]]==0)tag--;
            mp[nums[i]]++;
            if(mp[nums[i]]==1)tag++;
            else if(mp[nums[i]]==2)tag--;
            if(tag==k)ans=max(ans,tmp);
        }
        return ans;
    }
};
