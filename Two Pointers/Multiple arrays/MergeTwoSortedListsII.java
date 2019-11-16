/*
    Problem:
    Merge Two Sorted Lists II
    Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note: You have to modify the array A to contain the merge of A and B. Do not 
    output anything in your code.
    TIP: C users, please malloc the result into a new array and return the result. 
    If the number of elements initialized in A and B are m and n respectively, the 
    resulting size of array A after your code is executed should be m + n

    Example :

    Input : 
            A : [1 5 8]
            B : [6 9]

    Modified A : [1 5 6 8 9]
*/

/* 
    Solution:
    Time: O(N)
    Space: O(1)
    Approach:
        have two indexes and increment them exclusively when there is an 
        inequality.
*/

public class Solution {
    public void merge(ArrayList<Integer> a, ArrayList<Integer> b) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < a.size() && idx2 < b.size()) {
            if (a.get(idx1) < b.get(idx2))
                idx1++;
            else {
                a.add(idx1, b.get(idx2));
                idx2++;
            }
        }
        
        while (idx2  < b.size()) {
            a.add(a.size(), b.get(idx2));
            idx2++;
        }
    }
}
