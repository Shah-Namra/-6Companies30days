// 462. Minimum Moves to Equal Array Elements II

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long moves = 0;
        int left = 0, right = n - 1;
        
        while(left < right) {
            moves += nums[right] - nums[left];
            left++;
            right--;
        }
        
        return moves;
    }
};
// TC: O(nlogn), SC: O(1) 