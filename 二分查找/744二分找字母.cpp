class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        char result = letters[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        // 如果最后一个字符大于target，返回它
        if (letters[left] > target) {
            return letters[left];
        }

        return result; // 如果没有大于target的字符，返回第一个字符
    }
};