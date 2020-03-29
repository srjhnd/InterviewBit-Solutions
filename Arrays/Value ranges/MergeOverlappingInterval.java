/* Problem statement: 
    Given a collection of intervals, merge all overlapping intervals.
    For example:
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].
    Make sure the returned intervals are sorted.
*/

/* Solution:
    O(NlogN): time
    O(1): space

    1. define an interval comparator to sort intervals in ascending order 
    2. iterate over the sorted intervals and merge them accordingly.
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

public class Solution {
    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
        if (intervals.size() <= 1)
            return intervals;
        
        ArrayList<Interval> ret = new ArrayList<>();
        
        Collections.sort(intervals, (ivl1, ivl2) -> { return ivl1.start - ivl2.start; });
        
        Interval curr = intervals.get(0);
        Interval nxt = intervals.get(1);

        for (int i = 0; i < intervals.size()-1; i++) {
            nxt = intervals.get(i+1);
            if (curr.end >= nxt.start) {
                curr.start = Math.min(curr.start, nxt.start);
                curr.end = Math.max(curr.end, nxt.end);
            } else {
                ret.add(curr);
                curr = nxt;
            }
        }

        ret.add(curr);
        
        return ret;
    }
}
