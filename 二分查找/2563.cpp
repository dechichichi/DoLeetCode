class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            auto j1 = lower_bound(nums.begin(), nums.begin()+i, lower - nums[i]);
            auto j2 = upper_bound(nums.begin(), nums.begin()+i, upper - nums[i]);
            ans += j2 - j1;
        }
        return ans;
    }
};

