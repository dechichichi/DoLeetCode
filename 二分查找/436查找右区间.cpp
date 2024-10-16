
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        int index = 0;// 用于记数
        for (auto x : intervals) {
            mp.emplace(x[0], index);
            index++;
        } // 这里改成用有序表，插入后，是直接排序好的
        vector<int> ans; // 保存结果
        // 改进二分法，使用lower_bound,更简洁
        for (auto x : intervals) {
            auto y = mp.lower_bound(x[1]);
            if (y != mp.end()) {
                ans.push_back(y->second);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};