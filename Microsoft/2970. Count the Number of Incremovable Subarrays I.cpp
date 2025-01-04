// 2970. Count the Number of Incremovable Subarrays I

// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0;
        int n = nums.size();

        for(int i = 0;i < n; i++){
            for(int j = i; j < n ;j++){
                int last = -1;
                int flag=1;

                for(int k = 0; k < n; k++){
                    if(k >= i && k <= j)
                        continue;
                
                   if(last >= nums[k]){
                        flag=0;
                        break;
                    }
                    last = nums[k];
                }
                if(flag == 1) 
                    ans++;
            }
        }
        return ans;
    }
};

// TC: O(n^3) SC: O(1)