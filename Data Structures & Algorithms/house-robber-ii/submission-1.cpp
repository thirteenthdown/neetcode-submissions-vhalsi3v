class Solution {
private:
    int helperRob(vector<int>& nums, int start, int end){
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(helperRob(nums, 0, n-2), helperRob(nums, 1, n-1));
    }
};
