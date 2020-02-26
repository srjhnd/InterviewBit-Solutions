/* 
Problem statement: 
    Given an array, find the next greater element G[i] for every element A[i] in the array. The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array.
    More formally,

    G[i] for an element A[i] = an element A[j] such that 
        j is minimum possible AND 
        j > i AND
        A[j] > A[i]
    Elements for which no greater element exist, consider next greater element as -1.

    Example:

    Input : A : [4, 5, 2, 10]
    Output : [5, 10, 10, -1]

    Example 2:

    Input : A : [3, 2, 1]
    Output : [-1, -1, -1]


Solution:
    O(N): time
    O(N): space
*/

vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> stk;
    vector<int> ret(A.size(), -1);
    
    for (int i = A.size()-1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= A[i])
            stk.pop();
        ret[i] = (!stk.empty()) ? stk.top() : -1;
        stk.push(A[i]);
    }
    return ret;
}