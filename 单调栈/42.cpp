class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], height[i]) - bottom_h; // 面积的高
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};


