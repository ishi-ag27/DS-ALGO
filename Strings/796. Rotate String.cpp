//Approach 1 , Time complexity: O(n2)
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to check if goal can be formed by rotating string s
    bool rotateString(const string& s, const string& goal) {
        // Check if lengths of s and goal are equal
        if (s.length() != goal.length()) {
            return false; // If lengths are different, rotation is not possible
        }

        // Iterate through each possible rotation of s
        for (int i = 0; i < goal.length(); i++) {
            bool rotationPossible = true;

            // Compare characters of s with corresponding characters of goal
            for (int j = 0; j < s.length(); j++) {
                // Use modulo operator to handle rotation
                if (goal[(i + j) % goal.length()] != s[j]) {
                    rotationPossible = false;
                    break;
                }
            }

            // If rotation is possible, return true
            if (rotationPossible) {
                return true;
            }
        }

        // If no rotation matches goal, return false
        return false;
    }
};
