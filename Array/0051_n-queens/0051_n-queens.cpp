/*
 * Problem  : 51. N-Queens
 * Difficulty: Hard
 * Topics   : Array, Backtracking
 * URL      : https://leetcode.com/problems/n-queens/
 */

class Solution {
public:
    vector<vector<string>> ans;

    // Yeh function check karta hai ki queen ko (rowIdx, colIdx) pe rakhna safe hai ya nahi
    bool check(int rowIdx, int colIdx, int n, vector<vector<int>>& board) {
        // Row ke left side check karo
        for (int col = 0; col < colIdx; col++) {
            if (board[rowIdx][col] == 1)
                return false;
        }

        // Upper-left diagonal check karo
        int i = rowIdx, j = colIdx;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 1)
                return false;
            i--; j--;
        }

        // Lower-left diagonal check karo
        i = rowIdx; j = colIdx;
        while (i < n && j >= 0) {
            if (board[i][j] == 1)
                return false;
            i++; j--;
        }

        return true; // Safe hai queen rakhne ke liye
    }

    // Yeh helper function recursively queens place karta hai column by column
    void helper(int colIdx, vector<vector<int>>& board, int n) {
        // Agar saari queens place ho gayi, to solution store karo
        if (colIdx == n) {
            vector<string> config;
            for (int i = 0; i < n; i++) {
                string row = "";
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1)
                        row += 'Q';
                    else
                        row += '.';
                }
                config.push_back(row);
            }
            ans.push_back(config);
            return;
        }

        // Har row pe queen rakhne ki try karo
        for (int rowIdx = 0; rowIdx < n; rowIdx++) {
            if (check(rowIdx, colIdx, n, board)) {
                board[rowIdx][colIdx] = 1;         // Queen place karo
                helper(colIdx + 1, board, n);      // Next column ke liye call karo
                board[rowIdx][colIdx] = 0;         // Backtrack: queen hatao
            }
        }
    }

    // Main function jo sab kuch start karta hai
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0)); // Empty board banao
        helper(0, board, n); // Recursion start from column 0
        return ans;
    }
};