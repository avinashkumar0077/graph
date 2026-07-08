class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        
        vector<int> temarivolo = nums;

        vector<long long> ans;

        for (long long x : temarivolo) {   
            while (!ans.empty() && ans.back() == x) {
                x = ans.back() + x;
                ans.pop_back();
            }
            ans.push_back(x);
        }

        return ans;
    }
};



