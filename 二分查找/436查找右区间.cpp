
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        int index = 0;// ���ڼ���
        for (auto x : intervals) {
            mp.emplace(x[0], index);
            index++;
        } // ����ĳ���������������ֱ������õ�
        vector<int> ans; // ������
        // �Ľ����ַ���ʹ��lower_bound,�����
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