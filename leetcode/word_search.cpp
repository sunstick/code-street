/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool solve(int i, int j, int m, int n, int off, string &word, vector<vector<char> > &board, set<pair<int, int> > &ss) {
        if (off == word.size())
            return true;
        if (i == -1 || i == m || j == -1 || j == n)
            return false;
        pair<int, int> p(i, j);

        if (ss.count(p)) return false;


        if (board[i][j] != word[off])
            return false;

        ss.insert(p);
        return  solve(i - 1, j, m, n, off + 1, word, board, ss) ||
                solve(i + 1, j, m, n, off + 1, word, board, ss) ||
                solve(i, j - 1, m, n, off + 1, word, board, ss) ||
                solve(i, j + 1, m, n, off + 1, word, board, ss) ;
    }
    bool exist(vector<vector<char> > &board, string word) {
        set<pair<int, int> > ss;

        int m = board.size();
        int n = m ? board[0].size() : 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ss.clear();
                if (solve(i, j, m, n, 0, word, board, ss))
                    return true;
            }
        }

        return false;
    }
};