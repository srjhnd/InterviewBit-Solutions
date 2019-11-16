/*
    Problem:
    Subsets

    Given a set of distinct integers, S, return all possible subsets.

    Note:
    1. Elements in a subset must be in non-descending order.
    2. The solution set must not contain duplicate subsets.
    3. Also, the subsets should be sorted in ascending ( lexicographic ) order.
    4. The list is not necessarily sorted.

    Example :

    If S = [1,2,3], a solution is:
    [
    [],
    [1],
    [1, 2],
    [1, 2, 3],
    [1, 3],
    [2],
    [2, 3],
    [3],
    ]
*/

/* 
    Solution:
    Time: O(2^N)
    Space: O(2^N)
    Approach:
*/

public class Solution {
    
    public void backtrack(ArrayList<Integer> A, ArrayList<ArrayList<Integer>> ret,
                            ArrayList<Integer> lst, int idx) {
        ret.add(new ArrayList<Integer>(lst));
        for (int i = idx; i < A.size(); i++) {
            lst.add(A.get(i));
            backtrack(A, ret, lst, i+1);
            lst.remove(lst.size() - 1);
        }
    }
    
    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        
        if (A.size() <= 0) {
            ret.add(new ArrayList<Integer>());
            return ret;
        }

        Collections.sort(A);
        backtrack(A, ret, new ArrayList<Integer>(), 0);
        return ret;
    }
}
