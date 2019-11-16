

class Solution {
    
    public String largestNumber(int[] nums) {
        boolean allZeros = false;
        for (int i : nums) {
            if (i != 0)
                allZeros = true;
        }
        if (!allZeros)
            return "0";

        StringBuilder sb = new StringBuilder();
        Collections.sort(arr, (s1, s2) -> { return (s2+s1).compareTo(s1+s2); });
        
        for (String s : arr) {
            sb.append(s);
        }
        return sb.toString();
    }
}