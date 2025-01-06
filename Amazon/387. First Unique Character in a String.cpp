// 387. First Unique Character in a String

// https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        for (int i = 0; i <n;i++) {
        bool repeat = false;
            for (int j =0; j < n; j++) {
                if (i != j && s[i] == s[j]) {
                    repeat =true;
                    break;
                }
            }
        if (!repeat)  return i;
    }
    return -1;
    }
};
// TC: O(n^2) SC: O(1)