/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    void backtracking(vector<int> nums, vector<int> *track, vector<vector<int>> *res)
    {
        if (track->size() == nums.size())
        {
            res->push_back(*track);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (std::find(track->begin(), track->end(), nums[i]) != track->end())
                continue;
            track->push_back(nums[i]);
            backtracking(nums, track, res);
            track->pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> track;
        backtracking(nums, &track, &res);
        return res;
    }
};
// @lc code=end

// Note: backtracking
