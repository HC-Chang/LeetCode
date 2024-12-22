/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int chunks = 0, max_val = 0;

        for (int i = 0; i < n; i++)
        {
            max_val = max(max_val, arr[i]);
            if (max_val == i)
                chunks++;
        }

        return chunks;
    }
};
// @lc code=end

// Note: stack

// Official Solution