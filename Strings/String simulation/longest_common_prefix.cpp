/*
    Longest Common Prefix:

    Given the array of strings A,
    you need to find the longest string S which is the prefix of ALL the strings in
    the array.

    Longest common prefix for a pair of strings S1 and S2 is the longest string S
    which is the prefix of both S1 and S2.

    For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
*/


void compareAndStore(string &ret, string &str) {
  if (ret.length() > str.length()) {
    swap(ret, str);
  }

  int len = 0;
  while (len < ret.length()) {
    if (ret[len] == str[len])
      len++;
    else
      break;
  }
  ret = str.substr(0, len);
}

string Solution::longestCommonPrefix(vector<string> &A) {
  if (A.size() <= 0)
    return "";
  string ret = A[0];
  for (int i = 1; i < A.size(); i++) {
    compareAndStore(ret, A[i]);
  }
  return ret;
}
