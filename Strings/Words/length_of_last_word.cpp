/*
    Length of Last Word:
    
    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.

    Example:

    Given s = "Hello World",

    return 5 as length("World") = 5.
*/


int Solution::lengthOfLastWord(const string A) {
    int idx = A.length() - 1;
    int len = 0;
    bool firstChar = false;
    while (idx >= 0) {
        if (A[idx] == ' ' && firstChar)
            break;
        if (A[idx] != ' ') {
            len++;
            firstChar = true;
        }
        idx--;
    }
    return len;
}
