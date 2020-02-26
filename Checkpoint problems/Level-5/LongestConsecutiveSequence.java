/* 
Problem statement: 
    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

    Example:
    Given [100, 4, 200, 1, 3, 2],
    The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

    Your algorithm should run in O(n) complexity.

Solution:
    O(N): time
    O(N): space
*/

public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int longestConsecutive(final int[] A) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int count = 1;
        int ret = 1;
        for (int i : A) {
            if (!map.containsKey(i))
                map.put(i, 1);
        }
        Integer prev = Integer.MAX_VALUE;
        for (Integer i : map.keySet()) {
            if (prev == Integer.MAX_VALUE) {
                prev = i;
                continue;
            } 
            
        //    System.out.println("i: " + i + " diff: " + (i - prev));
            if ((i - prev) == 1)
                count++;
            else {
                ret = Math.max(ret, count);
                count = 1;
            }

            prev = i;
        }
        ret = Math.max(ret, count);
        return ret;
    }
}
