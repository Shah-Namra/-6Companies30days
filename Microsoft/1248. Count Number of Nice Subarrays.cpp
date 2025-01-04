// 1248. Count Number of Nice Subarrays

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
        }
        vector<int> prefix(n + 1);
        prefix[0] = 1;
        int count = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            count += nums[i];
            if (count >= k) {
                ans += prefix[count - k];
            }
            prefix[count]++;
        }

        return ans;
    }
};
// TC: O(n) SC: O(n)