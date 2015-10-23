/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    void solve(int off, vector<vector<int> > &res, vector<int> &num, vector<int> &v) {
        if(off == num.size()) {
            res.push_back(v);
            return ;
        }
        
        for(int i = off; i < num.size(); i++) {
            v.push_back(num[i]);
            swap(num[i], num[off]); // swapping, avoid to choose i again
            solve(off + 1, res, num, v);
            swap(num[i], num[off]);
            v.pop_back();
        }
        
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> v;
        
        solve(0, res, num, v);
        
        return res;
    }
};