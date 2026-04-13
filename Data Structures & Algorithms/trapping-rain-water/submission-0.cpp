class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int left = 0, right = height.size()-1;
        int left_max = 0, right_max = 0;
        int total_water = 0;
        while(left < right){
            if(height[left] < height[right]){
                left_max = max(height[left], left_max);
                total_water += left_max - height[left];
                left++;
            }
            else {
                right_max = max(height[right], right_max);
                total_water += right_max - height[right];
                right--;
            }
        }
        return total_water;
    }
};
