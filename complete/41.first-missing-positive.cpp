/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int small = 1;
        int n = nums.size();
        int visited[n + 2];
        memset(visited, 0, sizeof(visited));
        int tmp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= small && nums[i] < n + 1)
            {
                ++visited[nums[i]];
                if (nums[i] == small)
                {
                    tmp = small;
                    while (visited[tmp] > 0)
                        tmp++;
                    small = tmp;
                }
            }
        }
        return small;
    }
};
// @lc code=end

// Note: hash table