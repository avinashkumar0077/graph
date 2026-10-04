class Solution {
public:

    bool allZero(vector<int>& counter) {
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int n = s.length();
        int k = p.length();

        vector<int> counter(26, 0);

        // Store frequency of p
        for (int i = 0; i < k; i++) {
            counter[p[i] - 'a']++;
        }

        int i = 0;
        int j = 0;

        vector<int> result;

        while (j < n) {

            // Character enters the window
            counter[s[j] - 'a']--;

            // Window size becomes equal to p
            if (j - i + 1 == k) {

                // If all frequencies are zero,
                // current window is an anagram
                if (allZero(counter)) {
                    result.push_back(i);
                }

                // Character leaves the window
                counter[s[i] - 'a']++;

                // Move left pointer
                i++;
            }

            // Move right pointer
            j++;
        }

        return result;
    }
};