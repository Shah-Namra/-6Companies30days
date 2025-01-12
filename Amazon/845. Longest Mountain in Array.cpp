// 845. Longest Mountain in Array

// https://leetcode.com/problems/longest-mountain-in-array/description/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0, count = 1; 
        bool flag = 0;
        for(int i=1; i<A.size(); i++){
            if(A[i] > A[i-1]){
                if(flag == 1) flag = 0, count = 1;
                count++;
            }
            else if(count >= 2 and A[i] < A[i-1]){
                flag = 1;  count++;
                res = max(res, count);
            }
            else count = 1;
        }
        return res;
    }
};

// Time: O(N) 