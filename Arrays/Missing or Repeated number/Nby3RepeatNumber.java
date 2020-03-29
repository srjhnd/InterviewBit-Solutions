/*
    Problem:
    N/3 Repeat Number:
   
   You’re given a read only array of n integers. Find out if any integer occurs
   more than n/3 times in the array in linear time and constant additional
   space.

    If so, return the integer. If not, return -1.

    If there are multiple solutions, return any one.

    Example :

    Input : [1 2 3 1 1]
    Output : 1
    1 occurs 3 times which is more than 5/3 times.
*/

/*
    Solution:
    O(N): time
    O(1): space

    Moore's Voting algorithm:
    Count the first and second most probable candidate in O(N) once.
    Again count if first count or second count > N/3
 */

public class Solution {
	// DO NOT MODIFY THE LIST
	public int repeatedNumber(final List<Integer> A) {
        if (A.size() <= 0)
            return -1;
        int Nb3 = A.size() / 3;
        int firstCount = 0;
        int secondCount = 0;
        int firstNum = Integer.MAX_VALUE;
        int secondNum = Integer.MAX_VALUE;

        for (int n : A) {
            if (firstNum == n) 
                firstCount++;
            else if (secondNum == n)
                secondCount++;
            else if (firstCount == 0) {
                firstCount++;
                firstNum = n;
            } else if (secondCount == 0) {
                secondCount++;
                secondNum = n;
            } else if (n != firstNum && n != secondNum) {
                secondCount--;
                firstCount--;
            }
        }

        firstCount = 0;
        secondCount = 0;

        for (int n : A) {
            if (n == firstNum)
                firstCount++;
            else if (n == secondNum)
                secondCount++;
        }
        
        if (firstCount > Nb3)
            return firstNum;
        else if (secondCount > Nb3)
            return secondNum;
        

        return -1;
    }
}