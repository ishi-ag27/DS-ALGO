class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        int start = 0, maxLen = 1; // Initialize starting index and maximum length
        
        for (int i = 1; i < s.size(); i++) { // Iterate through the string
            // Odd-length palindromes (center at i)
            l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) { // Check if current palindrome is longer
                    maxLen = r - l + 1; // Update max length
                    start = l; // Update starting index
                }
                l--; // Expand outwards
                r++;
            }

            // Even-length palindromes (center between i-1 and i)
            l = i - 1;
            r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) { // Check if current palindrome is longer
                    maxLen = r - l + 1; // Update max length
                    start = l; // Update starting index
                }
                l--; // Expand outwards
                r++;
            }
        }
        
        return s.substr(start, maxLen); // Return the longest palindromic substring
    }
};
