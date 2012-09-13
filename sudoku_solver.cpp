int row[9];
int col[9];
int box[9];

bool ok(int i, int j, int v) {
    int k = 3 * (i / 3) + j / 3;
    if (row[i] & (1 << v)) return false;
    if (col[j] & (1 << v)) return false;
    if (box[k] & (1 << v)) return false;
    return true;
}

void setinfo(int i, int j, int v) {
    int k = 3 * (i / 3) + j / 3;
    row[i] |= (1 << v);
    col[j] |= (1 << v);
    box[k] |= (1 << v);
}

void unsetinfo(int i, int j, int v) {
    int k = 3 * (i / 3) + j / 3;
    row[i] &= ~(1 << v);
    col[j] &= ~(1 << v);
    box[k] &= ~(1 << v);
}

vector<pair<int, int> > empties;

bool solve(vector<vector<char> > &board, int count) {
    if (count == empties.size()) return true;
    int i = empties[count].first;
    int j = empties[count].second;

    for (int v = 1; v <= 9; v++) {
        if (ok(i, j, v)) {
            setinfo(i, j, v);
            board[i][j] = (v + '0');

            if (solve(board, count + 1)) return true;

            unsetinfo(i, j, v);
            board[i][j] = '.';
        }
    }

    return false;
}

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        empties.clear();
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    empties.push_back(make_pair(i, j));
                else
                    setinfo(i, j, board[i][j] - '0');
        solve(board, 0);
    }
};