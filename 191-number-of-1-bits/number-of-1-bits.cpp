class Solution {
public:
    int hammingWeight(int n) {
        int count;
        while(n > 0){
            if(n & 1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};