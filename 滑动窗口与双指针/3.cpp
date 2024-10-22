class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[256] = {0}; // 初始化数组为0
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.size()) {
            if (!a[s[r]]) { // 只有当字符没有出现过时才增加r
                a[s[r]]++;
                r++;
            } else {
                ans = max(ans, r - l); // 更新答案
                while (a[s[r]]) { // 移动l直到没有重复字符
                    a[s[l]]--;
                    l++;
                }
                a[s[r]]++; // 再次增加r位置字符的计数
                r++;
            }
        }
        ans = max(ans, r - l); // 最后一次更新答案
        return ans;
    }
};
