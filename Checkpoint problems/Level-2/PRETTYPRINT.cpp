/* 
Problem statement: 
    Print concentric rectangular pattern in a 2d matrix.
    Let us show you some examples to clarify what we mean.

    Example 1:

    Input: A = 4.
    Output:

    4 4 4 4 4 4 4 
    4 3 3 3 3 3 4 
    4 3 2 2 2 3 4 
    4 3 2 1 2 3 4 
    4 3 2 2 2 3 4 
    4 3 3 3 3 3 4 
    4 4 4 4 4 4 4 
    Example 2:

    Input: A = 3.
    Output:

    3 3 3 3 3 
    3 2 2 2 3 
    3 2 1 2 3 
    3 2 2 2 3 
    3 3 3 3 3 
    The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.
    You will be given A as an argument to the function you need to implement, and you need to return a 2D array. 


Solution:
    O(N): time
    O(N): space
*/


vector<vector<int> > Solution::prettyPrint(int A) {
    int sz = 2 * A - 1;
    vector<vector<int>> ret(sz, vector<int>(sz, 0));
    int num = A;
    int top = 0, bottom = sz-1, right = sz-1, left = 0;
    while (right >= left) {
        for (int i = left; i <= right; i++) 
            ret[top][i] = num;
        top++;
        for (int i = top; i <= bottom; i++)
            ret[i][right] = num;
        right--;
        for (int i = right; i >= left; i--)
            ret[bottom][i] = num;
        bottom--;
        for (int i = bottom; i >= top; i--)
            ret[i][left] = num;
        left++;
        num--;
    }
    return ret;
}
