// 168. Excel Sheet Column Title

// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber > 0) {
            columnNumber--;
            res = char(columnNumber % 26 + 'A') + res;
            columnNumber /= 26;
        }
        return res;
    }
};

// TC: O(log(columnNumber)) SC: O(1)
