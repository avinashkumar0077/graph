class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
     int i = 0;
     int j = n-1;
     int leftMax = 0;
     int rightMax=0;
     int water = 0;
     while(i<j){
        if(height[i] < height[j]){
            leftMax = max(height[i],leftMax);
            water += leftMax - height[i];
            i++;
        }else{
            rightMax = max(height[j],rightMax);
            water += rightMax - height[j];
            j--;
        }
     }
     return water;
   }
};