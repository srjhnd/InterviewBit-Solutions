/* 
Problem statement: 
    Find the kth smallest element in an unsorted array of non-negative integers.

    Definition of kth smallest element

    kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
    In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based ) 
    NOTE
    You are not allowed to modify the array ( The array is read only ).
    Try to do it using constant extra space.

    Example:

    A : [2 1 4 3 2]
    k : 3

    answer : 2


Solution:
    O(N): time
    O(N): space
*/

int Solution::kthsmallest(const vector<int> &A, int B)
{
    int high = INT_MIN;
    int low = INT_MAX;

    for (int i : A)
    {
        high = max(high, i);
        low = min(low, i);
    }

    while (low <= high)
    {
        int less = 0, equal = 0;
        int mid = (high + low) / 2;
        for (int i : A)
        {
            if (i < mid)
                less++;
            else if (i == mid)
                equal++;
        }

        if (less < B && (less + equal) >= B)
            return mid;
        else if (less >= B)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
