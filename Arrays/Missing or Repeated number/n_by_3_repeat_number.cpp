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

    Voting algorithm:
    Count the first and second most probable candidate in O(N) once.
    Again count if first count or second count > N/3
 */

int Solution::repeatedNumber(const vector<int> &A) {
  if (A.size() <= 0)
    return -1;
  int first = INT_MAX, second = INT_MAX;
  int countf = 0, counts = 0;
  int N3 = A.size() / 3;
  for (int i = 0; i < A.size(); i++) {
    if (first == A[i]) {
      countf++;
    } else if (second == A[i]) {
      counts++;
    } else if (countf == 0) {
      countf++;
      first = A[i];
    } else if (counts == 0) {
      counts++;
      second = A[i];
    } else if (A[i] != first && A[i - 1] != second) {
      countf--;
      counts--;
    }
  }

  countf = 0;
  counts = 0;

  for (int i = 0; i < A.size(); i++) {
    if (A[i] == first)
      countf++;
    else if (A[i] == second)
      counts++;
  }
  if (countf > N3)
    return first;
  else if (counts > N3)
    return second;
  else
    return -1;
}
