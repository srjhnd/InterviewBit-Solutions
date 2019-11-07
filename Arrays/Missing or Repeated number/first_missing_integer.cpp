/*
    First Missing Integer:

    Given an unsorted integer array, find the first missing positive integer.

    Example:
    Given [1,2,0] return 3,
    [3,4,-1,1] return 2,
    [-8, -7, -6] returns 1
    Your algorithm should run in O(n) time and use constant space.
*/

/* Solution:
    Time: O(N)
    Space: O(1)
    Approach:
        step 1: For each element A[i], check if it is at A[i]-1 index. If not, swap
            it with A[A[i]-1] until A[i] = A[A[i]-1]
        step 2: Then iterate through the array and check for the first missing element.

        Example:
        Consider an array [1, 3, 6, 4, -1, 2]
        The resulting array after step 1 would be [1, 2, 3, 4, -1, 6]

        i = 0, array = ["1", 3, 6, 4, -1, 2] no swap required since A[0] = 1
        i = 1, array = [1, "6", "3", 4, -1, 2] inside while loop
        i = 1, array = [1, "2", 3, 4, -1, "6"] since A[1] = 2 while loop exits.
        i = 2, array = [1, 2, "3", 4, -1, 6] no swap required A[2] = 3
        i = 3, array = [1, 2, 3, "4", -1, 6] no swap required A[3] = 4
        i = 4, array = [1, 2, 3, 4, "-1", 6] no swap required A[4] < 1
        i = 5, array = [1, 2, 3, 4, -1, "6"] no swap required A[5] = 6

        Finally check to see if any element is missing in the sequence and return 
        the missing number.
*/                         

int Solution::firstMissingPositive(vector<int> &A) {

    for (int i = 0; i < A.size(); i++) {
        while (A[i] > 0 && A[i] <= A.size() && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i]-1]);
        }
    }
    
     for(int i = 0; i < A.size(); i++)
        if(A[i] != i + 1)
            return i + 1;
    return A.size()+1;
}
