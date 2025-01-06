// 2461. Maximum Sum of Distinct Subarrays With Length K

// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi=0;
        long long sum=0;
        unordered_map<int,int>mp;
      int i = 0,j =0;
      int n =nums.size();
        while(j < nums.size()){
            mp[nums[j]]++;
            sum += nums[j];

            if(j - i+ 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                if(mp.size() == k){
                    maxi = max(maxi,sum);
                }

                mp[nums[i]]--;

                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }

                sum -= nums[i];
                 i++;
            j++;
                
            }
           
            
        }
        return maxi;
    }
};
// TC: O(n) SC: O(n)