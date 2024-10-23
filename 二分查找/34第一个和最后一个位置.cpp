class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int l = 0, r = nums.size() - 1;
        int tag1 = -1, tag2 = -1;
        
        // Ñ°ÕÒ×îÓÒ±ß½ç
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l < nums.size() && nums[l] == target) {
            tag1 = l;
        } else {
            return {-1, -1};
        }
        
        // ÖØÖÃ×óÓÒ±ß½ç£¬Ñ°ÕÒ×î×ó±ß½ç
        r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        tag2 = r;
        if (r < 0 || nums[r] != target) {
            tag2 = -1;
        }
        
        return {tag1, tag2};
    }
};
