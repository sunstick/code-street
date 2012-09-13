class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows[9];
        int columns[9];
        int boards[9];

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(boards, 0, sizeof(boards));

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int r = i, c = j;
                int b = 3 * (i / 3) + j / 3;

                int value = board[i][j] - '0';

                if (value < 1 || value > 9) return false;
                if (rows[r] & (1 << value)) return false;
                if (columns[c] & (1 << value)) return false;
                if (boards[b] & (1 << value)) return false;

                rows[r] |= (1 << value);
                columns[c] |= (1 << value);
                boards[b] |= (1 << value);
            }

        return true;
    }
};