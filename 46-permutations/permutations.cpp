class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        backtrack(nums, 0, ans);
        
        return ans;
    }
    
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& ans) {
        // If we have placed all elements
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            // Choose
            swap(nums[start], nums[i]);
            
            // Explore
            backtrack(nums, start + 1, ans);
            
            // Undo choice
            swap(nums[start], nums[i]);
        }
    }
};