class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int left = 0;   // 窗口左边界
        int cost = 0;   // 当前窗口消耗
        // i作为窗口右边界
        for (int i = 0; i < s.size(); i++)
        {
            cost += std::abs(s[i] - t[i]);
            // 如果当前窗口消耗大于总开销，则左边界++，缩减窗口
            if (cost > maxCost)
            {
                cost -= std::abs(s[left] - t[left]);
                left++;
            }
        }
        return s.size() - left;
    }
};
