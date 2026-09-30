#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& ans) {

        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            // Choose the current number
            current.push_back(candidates[i]);

            // Move to next index because
            // each element can be used only once
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current,
                      ans);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> ans;
        vector<int> current;

        // Sorting helps us handle duplicates
        // and stop early when candidate > target
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, ans);

        return ans;
    }
};