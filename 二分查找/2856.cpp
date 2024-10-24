class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int tag=nums[n/2];
       int max_cnt = ranges::upper_bound(nums, tag) - ranges::lower_bound(nums, tag);
        return max(max_cnt * 2 - n, n % 2);
    }
};
