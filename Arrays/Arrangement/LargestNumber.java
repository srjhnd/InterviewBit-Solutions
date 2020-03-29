/*
    Problem:

    Given a list of non negative integers, arrange them such that they form the largest number.
    For example:
    Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
    Note: The result may be very large, so you need to return a string instead of an integer.

*/

/*  
    Solution:
    Time: O(NlogN)
    Space: O(N)
    Approach:
        This can be solved by using a custom comparator with java collections (or equivalent 
        collections framework in other programming languages). 

        Time complexity would be O(NlogN) since we are sorting the array(O(NlogN)) and going through it
        once(O(N)).

        Space complexity is O(N) to store the result which is the same size as the input.
*/                    

class Solution {
    
    public String largestNumber(final int[] nums) {
        boolean allZeros = true;

        List<String> arr = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();
        for (int i : nums) {
            arr.add(Integer.toString(i));
            if (i != 0)
                allZeros = false;
        }
        if (allZeros)
            return "0";
        Collections.sort(arr, (s1, s2) -> { return (s2+s1).compareTo(s1+s2); });
        
        for (String s : arr) {
            sb.append(s);
        }
        return sb.toString();
    }
}