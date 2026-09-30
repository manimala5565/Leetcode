#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int right = 0;
        int maxLength = 0;

        while (right < s.length()) {
            
            // If character is not present
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
            else {
                // Remove characters from left
                st.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};