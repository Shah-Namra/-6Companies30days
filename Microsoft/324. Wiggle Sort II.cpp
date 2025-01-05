// 324. Wiggle Sort II

// https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int>temp (nums);
        sort(temp.begin(),temp.end());
        int n = nums.size();
        int j = n - 1;
        
        for(int i = 1;i < n;i += 2){
            nums[i] = temp[j];
            j--;
        }
        for(int i = 0;i < n;i += 2){
            nums[i] = temp[j];
            j--;
        }
    }
};

// TC: O(nlogn) SC: O(n)