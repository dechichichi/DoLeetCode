class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[256] = {0}; // ��ʼ������Ϊ0
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.size()) {
            if (!a[s[r]]) { // ֻ�е��ַ�û�г��ֹ�ʱ������r
                a[s[r]]++;
                r++;
            } else {
                ans = max(ans, r - l); // ���´�
                while (a[s[r]]) { // �ƶ�lֱ��û���ظ��ַ�
                    a[s[l]]--;
                    l++;
                }
                a[s[r]]++; // �ٴ�����rλ���ַ��ļ���
                r++;
            }
        }
        ans = max(ans, r - l); // ���һ�θ��´�
        return ans;
    }
};
