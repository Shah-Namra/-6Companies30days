// 368. Largest Divisible Subset

// https://leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        sort(nums.begin(), nums.end());
        int index =0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) &&(1 + dp[j] > dp[i])) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                    if (maxi < dp[i]) {
                        maxi = dp[i];
                        index = i;
                    }
                }
            }
        }
        vector<int> ans;
        while (index != -1) {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time: O(N^2)