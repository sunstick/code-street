/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;

        for (int i = 0; i < intervals.size(); i++) {
            int s1 = intervals[i].start;
            int e1 = intervals[i].end;

            int s2 = newInterval.start;
            int e2 = newInterval.end;

            if ((s1 <= s2 && s2 <= e1) || (s2 <= s1 && s1 <= e2)) { // embedded
                newInterval.start = min(s1, s2);
                newInterval.end = max(e1, e2);
            } else if (e1 < s2) {
                res.push_back(intervals[i]);
            } else if (e2 < s1) {
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++)
                    res.push_back(intervals[j]);
                return res;
            } else {
                cout << "should not happen";
            }


        }
        res.push_back(newInterval);
        return res;
    }
};