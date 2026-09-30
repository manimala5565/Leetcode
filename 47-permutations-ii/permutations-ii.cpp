class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current) {
        // All elements are used
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Skip already used element
            if (used[i])
                continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used, current);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> current;

        backtrack(nums, used, current);

        return ans;
    }
};