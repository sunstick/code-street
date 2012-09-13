/*
Ideas: There are 3 important parameters in this algorithm, skip_idnex, i, j. If
num[skip_index], num[i], num[j] is added to 0. We add them to the result.

The loop maintains an important invariant: skip_index < i < j. (See the code for
how the loop invariant is maintained)
Since the array is sorted, we have num[skip_index] < num[i] < num[j].

Now let's explain how the algorithm avoids duplicates. For the ease of explanation,
let's assume the first found triplets are num[k] < num[i] < num[j], and the duplicated
triplets are num[dk] < num[di] < num[dj]. Now duplication occurs if and only if
num[k] == num[dk] and num[i] == num[di] and num[j] == num[dj].
Since array is sorted, supposing num[k] == num[dk] == 4, we have the following situation:
elements:   4 4 4 4 4 4
indexes:    k ....... dk

So there are only the same elements between k and dk.

So if we want to avoid searching duplicated k's, i's and j's, we need special logic
to increase k, increase i and decrease j. This is what the increase function and decrease
function does.

In summary, duplication removal is achieved by imposing a searching order when
searching the array and avoiding searching same elements.
*/

int increase(vector<int> &num, int i) {
    int newi = i + 1;
    while (newi < num.size() && num[newi] == num[i])
        newi++;
    return newi;
}

int decrease(vector<int> &num, int i) {
    int newi = i - 1;
    while (newi >= 0 && num[newi] == num[i])
        newi--;
    return newi;
}

void solve(vector<vector<int> > &res, vector<int> &num, int target, int skip_index) {
    int i = skip_index + 1;
    int j = num.size() - 1;

    vector<int> temp;

    while (i < j) {
        temp.clear();
        if (num[i] + num[j] == target) {
            temp.push_back(num[skip_index]);
            temp.push_back(num[i]);
            temp.push_back(num[j]);
            i = increase(num, i);
            j = decrease(num, j);
            res.push_back(temp);
        } else if (num[i] + num[j] < target) {
            i = increase(num, i);
        } else {
            j = decrease(num, j);
        }

    }
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i = increase(num, i))
            solve(res, num, 0 - num[i], i);

        return res;
    }
};