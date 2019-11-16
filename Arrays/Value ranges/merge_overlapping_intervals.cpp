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

struct IntervalComparator {
    bool operator() (const struct Interval& a, const struct Interval& b) {
        return a.start < b.start;
    }
};

vector<Interval> Solution::merge(vector<Interval> &A) {
    if (A.size() <= 1)
        return A;

    vector<Interval> ret;
    sort(A.begin(), A.end(), IntervalComparator()); // O(nlogn) a decent sorting algorithm.
    Interval tmp(A[0].start, A[0].end);
 
    Interval curr = A[0];
    Interval nxt = A[1];
    
    for (int i = 0; i < A.size() - 1; i++) {
        nxt = A[i+1];
        if (curr.end >= nxt.start) {
            curr.start = min(curr.start, nxt.start);
            curr.end = max(curr.end, nxt.end);
        } else {
            ret.push_back(curr);
            curr = nxt;
        }
    }
    ret.push_back(curr);
    return ret;
}
