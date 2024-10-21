class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        const int BIAS = 50;
        int cnt[BIAS * 2 + 1]{}, n = nums.size();
        for (int i = 0; i < k - 1; ++i) // ������������� k-1 ����
            ++cnt[nums[i] + BIAS];
        vector<int> ans(n - k + 1);
        for (int i = k - 1; i < n; ++i) {
            ++cnt[nums[i] + BIAS]; // ���봰�ڣ���֤������ǡ�� k ������
            int left = x;
            for (int j = 0; j < BIAS; ++j) { // ����ö�ٸ�����Χ [-50,-1]
                left -= cnt[j];
                if (left <= 0) { // �ҵ�����ֵ
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }
            --cnt[nums[i - k + 1] + BIAS]; // �뿪����
        }
        return ans;
    }
};
