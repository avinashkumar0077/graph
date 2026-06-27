class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            ans = max(ans, (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1]);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long x = start;
            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {
                len += 2;

                // Prevent overflow
                if (x > 1000000000LL)
                    break;

                x = x * x;
            }

            if (freq.count(x))
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};