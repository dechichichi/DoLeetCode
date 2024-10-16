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
        // ������һ���ַ�����target��������
        if (letters[left] > target) {
            return letters[left];
        }

        return result; // ���û�д���target���ַ������ص�һ���ַ�
    }
};