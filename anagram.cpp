#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // If the lengths of the strings are not equal, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Create a frequency map for characters in string s
        std::unordered_map<char, int> charCount;
        
        for (char c : s) {
            charCount[c]++;
        }
        
        // Check the characters in string t against the frequency map
        for (char c : t) {
            // If the character doesn't exist in the map or its count goes below zero, return false
            if (charCount[c] == 0) {
                return false;
            }
            charCount[c]--;
        }
        return true;
    }
};
