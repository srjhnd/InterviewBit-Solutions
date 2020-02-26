/* 
Problem statement: 
    Given an array A, count the number of inversions in the array.

    Formally speaking, two elements A[i] and A[j] form an inversion if A[i] > A[j] and i < j

    Example:

    A : [2, 4, 1, 3, 5]
    Output : 3
    as the 3 inversions are (2, 1), (4, 1), (4, 3).

Solution:
    O(N): time
    O(N): space
*/

int Solution::countInversions(vector<int> &A) {
    vector<int> dp(A.size(), 0);
    
    for (int i = 1; i < A.size(); i++) {
        int count = 0;
        for (int j = 0; j < i; j++)
            if (A[j] > A[i]) count++;
        dp[i] = dp[i-1] + count;
    }
    return dp[A.size()-1];
}
