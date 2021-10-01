# Longest Substring Without Repeating Characters
"""
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0

Time Complexity: O(n^2)

Space Complexity: O(n)

where n is the number of characters in the string.

"""


def lengthOfLongestSubstring(s: str) -> int:
    res = 0
    len_ = len(s)
    for i in range(0, len_):
        for j in range(i + 1, len_):
            if s.find(s[j], i, j) >= 0:
                if len(s[i:j]) > res:
                    res = len(s[i:j])
                break
            elif j == len_ - 1:
                if len(s[i:j + 1]) > res:
                    res = len(s[i:j + 1])
    if res == 0:
        return len_
    else:
        return res


print(lengthOfLongestSubstring("pwwkew"))

