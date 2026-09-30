#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    string keypad[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string current) {
        
        // All digits are processed
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get letters for current digit
        string letters = keypad[digits[index] - '0'];

        // Try every letter
        for (char ch : letters) {
            current.push_back(ch);

            backtrack(digits, index + 1, current);

            // Remove last character
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return result;
    }
};