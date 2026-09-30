#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Find first occurrence
    int findFirst(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;

                // Search further left
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    // Find last occurrence
    int findLast(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;

                // Search further right
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        return {first, last};
    }
};