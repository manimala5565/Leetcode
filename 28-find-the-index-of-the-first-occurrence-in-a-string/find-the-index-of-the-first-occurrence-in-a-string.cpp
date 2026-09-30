#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        // Try every possible starting position
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare characters
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // Complete needle matched
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};