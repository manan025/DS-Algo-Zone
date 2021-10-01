
// function which returns the maximum length of the substring without the repeating characters
var lengthOfLongestSubstring = function (s) {
    // returning zero if length is zero
    if (!s.length) return 0;
    let end = 0;
    let begin = 0;
    let maxLength = 0;
    const map = new Map();

    while (end < s.length) {
        let char = s[end];
        if (map.has(char)) {
            while (map.has(char)) {
                const beginChar = s[begin];
                map.delete(beginChar);
                begin++;
            }
        } else {
            map.set(char, 1);
            const len = end - begin + 1;
            if (len > maxLength) {
                maxLength = len;
            }
            end++;
        }
    }

    return maxLength;
};

function main() {
    // string to find in the longest substring
    const s="abcabcbb";
  
    const length=lengthOfLongestSubstring(s);
    if(length>0){
        // adding condition for length
        return length;
    }
    return 0;
  }
  
  main();

// Input: String in which we have to find the longest substring with repeating characters
// Output: Returns the length of the substring

//   ----------------------------------------
// Sample Input:
// "bbbbb"
// 
// Output:
// 1

// Sample Input:
// "pwwkew"
// 
// Output:
// 3

// ----------------------------------------

