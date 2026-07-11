//remember set is storing unique value
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       unordered_set<int>st;
       vector<int>ans;
       for(int i =0;i<n;i++){
        st.insert(nums1[i]);
       }
       for(int i =0;i<nums2.size();i++){
        if(st.find(nums2[i])!=st.end()){
            ans.push_back(nums2[i]);
            st.erase(nums2[i]);
        }
       }
       return ans;
    }
};