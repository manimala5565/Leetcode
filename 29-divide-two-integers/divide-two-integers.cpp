#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        // Find the quotient using powers of 2
        while (a >= b) {

            long long value = b;
            long long multiple = 1;

            // Double divisor using left shift
            while ((value << 1) <= a) {
                value = value << 1;
                multiple = multiple << 1;
            }

            // Subtract the largest possible value
            a -= value;
            quotient += multiple;
        }

        // Apply sign
        if (negative)
            quotient = -quotient;

        // 32-bit range check
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};