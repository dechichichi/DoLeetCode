#include<iostream>
#include<vector>
using namespace std;
vector<int> front;
vector<int> after;
void fdfs(int tag, vector<int>& nums, int left[], int right[]) {
    if (tag == 0) return;
    front.push_back(nums[tag]);
    if (left[tag] != 0) fdfs(left[tag], nums, left, right);
    if (right[tag] != 0) fdfs(right[tag], nums, left, right);
}

void adfs(int tag, vector<int>& nums, int left[], int right[]) {
    if (tag == 0) return;
    if (left[tag] != 0) adfs(left[tag], nums, left, right);
    if (right[tag] != 0) adfs(right[tag], nums, left, right);
    after.push_back(nums[tag]);
}

int main() {
    int n;
    cin >> n;
    int left[n+1] = {0}; // 初始化为0
    int right[n+1] = {0}; // 初始化为0
    int fa[n+1] = {0}; // 初始化为0
    int a;
    int tag = 0; // 初始化tag
    vector<int> nums(n);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 0) tag = i;
        fa[i] = a;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums[i] = a;
    }
    //根据中序遍历构建树
    for (int i = 0; i < nums.size() - 1; i++) {
        if (fa[nums[i]] == nums[i + 1]) {
            left[nums[i + 1]] = nums[i];
        } else if (fa[nums[i]] == nums[i - 1]) {
            right[nums[i - 1]] = nums[i];
        }
    }
    // 先序遍历
    fdfs(tag, nums, left, right);
    // 后序遍历
    adfs(tag, nums, left, right);
    for (auto i : front) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : after) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}