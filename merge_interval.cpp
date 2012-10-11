/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval &inter1, const Interval &inter2) {
    return inter1.start < inter2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;

        sort(intervals.begin(), intervals.end(), cmp);
        int s = -1, e = -1;

        for (int i = 0; i < intervals.size(); i++) {
            if (s == -1) {
                s = intervals[i].start;
                e = intervals[i].end;
                continue;
            }

            if (e < intervals[i].start) { // no overlap
                res.push_back(Interval(s, e));
                s = intervals[i].start;
                e = intervals[i].end;
            } else { // overlap
                e = max(e, intervals[i].end);
            }
        }

        if (s != -1)
            res.push_back(Interval(s, e));

        return res;
    }
};
