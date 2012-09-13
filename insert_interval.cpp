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