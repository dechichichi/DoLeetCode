

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // ��ʼ�� ans ����������Ԫ��Ϊ 0
        stack<int> tmp;
        int n = temperatures.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty()&& temperatures[tmp.top()] <= temperatures[i]) {
                tmp.pop();
            }
            if (!tmp.empty()) {
                int inx=tmp.top();
                ans[i]=inx-i;
            }
            tmp.push(i);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // ��ʼ�� ans ����������Ԫ��Ϊ 0
        stack<int> tmp;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && temperatures[tmp.top()] < temperatures[i]) {
                int idx = tmp.top();
                tmp.pop();
                ans[idx] = i - idx; // ����ȴ�������
            }
            tmp.push(i);
        }
        return ans;
    }
};
