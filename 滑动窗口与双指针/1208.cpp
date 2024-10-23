class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int left = 0;   // ������߽�
        int cost = 0;   // ��ǰ��������
        // i��Ϊ�����ұ߽�
        for (int i = 0; i < s.size(); i++)
        {
            cost += std::abs(s[i] - t[i]);
            // �����ǰ�������Ĵ����ܿ���������߽�++����������
            if (cost > maxCost)
            {
                cost -= std::abs(s[left] - t[left]);
                left++;
            }
        }
        return s.size() - left;
    }
};
