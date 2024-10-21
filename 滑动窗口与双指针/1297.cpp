class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map<string, int> idx;

        for (int i = 0; i < s.length() - minSize + 1; i ++ )
        {
            string str = s.substr(i, minSize);
            unordered_set<char> exist(str.begin(), str.end());

            if (exist.size() <= maxLetters)
            {
                idx[str] ++ ;
                ans = max(ans, idx[str]);
            }
        }

        return ans;

    }
};
