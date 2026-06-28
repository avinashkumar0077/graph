class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int i =0;
    int j =n-1;
    int k =n-1;
    vector<int>ans(n);
    while(i<=j){
        int leftSq=nums[i]*nums[i];
        int rightSq=nums[j]*nums[j];
        if(leftSq > rightSq){
            ans[k--] =leftSq;
            i++;
        }else{
            ans[k--] =rightSq;
            j--;
        }

    }
    return ans;
    }
};