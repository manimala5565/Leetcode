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

        // Try every candidate
        for (int i = start; i < candidates.size(); i++) {

            // If candidate is greater than target, skip it
            if (candidates[i] > target)
                continue;

            // Choose candidate
            current.push_back(candidates[i]);

            // i is passed again because
            // the same number can be used repeatedly
            backtrack(candidates,
                      target - candidates[i],
                      i,
                      current,
                      ans);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, ans);

        return ans;
    }
};