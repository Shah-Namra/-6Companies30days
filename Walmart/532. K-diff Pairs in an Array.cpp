// 532. K-diff Pairs in an Array

// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int, int>> unique_pairs; 

        for (int i=0; i < n ; i++){
            for(int j = i + 1; j< n; j++){
                if(abs(nums[i] - nums[j]) == k) {
                    int smaller = min(nums[i], nums[j]);
                    int larger = max(nums[i], nums[j]);
                    unique_pairs.insert({smaller, larger});
                }
            }
        }
        return unique_pairs.size();
    }
};

// Time: O(N^2)