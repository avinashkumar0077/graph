class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Transform array:
        // target -> +1
        // others -> -1
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        // Coordinate Compression
        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> bit(vals.size() + 2, 0);

        auto update = [&](int idx) {
            while (idx < bit.size()) {
                bit[idx]++;
                idx += idx & (-idx);
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += query(idx - 1);
            update(idx);
        }

        return ans;
    }
};