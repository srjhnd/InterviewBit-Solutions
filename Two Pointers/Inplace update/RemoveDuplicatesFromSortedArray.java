/*
    Problem:
    Remove duplicates from Sorted Array
    Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

    Note that even though we want you to return the new length, make sure to change the original array as well in place

    Do not allocate extra space for another array, you must do this in place with constant memory.

    Example:
    Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2].
*/

/* 
    Solution:
    Time: O(N)
    Space: O(1)
    Approach:
        Two pointers, idx = 0, peek = idx+1 increment peek when there are
        duplicates and swap the next inequal elements with idx+1.
*/

public class Solution {
    public int removeDuplicates(ArrayList<Integer> a) {
        if (a.size() <= 1)
            return a.size();
        int ret = 0;
        int idx = 0;
        int peek = idx+1;
        int sz = a.size();
        
        while (idx < sz && peek < sz) {
            while (peek < sz && a.get(idx) == a.get(peek))
                peek++;
            if (peek < sz && (peek - idx) > 1)
                a.set(idx+1, a.get(peek));
            idx++;
            ret++;
        }
        
        return ret;
    }
}
