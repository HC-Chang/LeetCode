/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> hash(26);
        int tasksSize = tasks.size();
        for (int i = 0; i < tasksSize; i++)
            hash[tasks[i] - 'A']++;

        int max_count = 0;
        int remain = 0;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] > max_count)
            {
                max_count = hash[i];
                remain = 1;
            }
            else if (hash[i] == max_count)
                remain++;
        }

        int r = (max_count - 1) * (n + 1) + remain;
        return max(r, tasksSize);
    }
};
// @lc code=end
