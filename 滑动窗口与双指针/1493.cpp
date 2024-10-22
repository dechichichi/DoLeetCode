class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int tag=0;
        int l=0,r=0;
        int ans=0;
        while(r<nums.size()){
            if(!nums[r])tag++;
            if(tag<=1){
                r++;
            }
            else{
                while(tag>1){
                    ans=max(ans,r-l-1);
                    tag-=nums[l]==0?1:0;
                    l++;
                }
                r++;
            }
        }
        ans=max(ans,r-l-1);
        return ans;
    }
};
