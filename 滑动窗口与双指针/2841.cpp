class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        map<int,int>mp;
        long long ans=0;
        int tag=0;
        long long tmp=0;
        for(int i=0;i<k;i++){
        mp[nums[i]]++;
        if(mp[nums[i]]==1)tag++;
        tmp+=nums[i];
        }
        if(tag>=m)ans=tmp;
        for(int i=k;i<nums.size();i++){
            tmp-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)tag--;
            tmp+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1)tag++;
            if(tag>=m)ans=max(ans,tmp);
        }
        return ans;
    }
};
