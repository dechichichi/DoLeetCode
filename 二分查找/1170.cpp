class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {
        int wordCount = words.size();
        vector<int> wordFreq(wordCount, 0);

        for (int i = 0; i < wordCount; i++) {
            wordFreq[i] = getFrequency(words[i]);
        }

        sort(wordFreq.begin(), wordFreq.end());

        int queryCount = queries.size();
        vector<int> result(queryCount, 0);

        for (int i = 0; i < queryCount; i++) {
            int queryFreq = getFrequency(queries[i]);
            result[i] =
                wordFreq.size() - lower_bound(wordFreq, queryFreq + 1);
        }

        return result;
    }

private:
    int getFrequency(const string& str) {
        char smallestChar = 'z';
        int freqCount = 0;

        for (char c : str) {
            if (c < smallestChar) {
                smallestChar = c;
                freqCount = 1;
            } else if (c == smallestChar) {
                freqCount++;
            }
        }

        return freqCount;
    }

    int lower_bound(const vector<int>& nums, int target) {
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

