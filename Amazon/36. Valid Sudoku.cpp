// 36. Valid Sudoku

// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool is_poss(vector<vector<char>>& a, int ii, int jj, char num) {
        for (int i = 0; i < 9; i++) {
            if (a[i][jj] == num || a[ii][i] == num)
                return false;
        }

        int row = (ii / 3) * 3;
        int col = (jj / 3) * 3;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (a[i][j] == num)
                    return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9; i++){
            for(int j = 0 ;j < 9; j++)
            if(board[i][j] != '.'){
                 char num = board[i][j];
                 board[i][j] = '.';
                if(is_poss(board , i ,j ,num)==0)
                    return 0;
            }
        }
        return 1;
    }
};
// TC: O(1)