/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> pq;
        int gap;
        for (int i = 1; i < n; i++)
        {
            gap = heights[i] - heights[i - 1];
            if (gap <= 0)
                continue;
            if (gap <= bricks)
            {
                pq.push(gap);
                bricks -= gap;
            }
            else
            {
                pq.push(gap);
                bricks -= gap;
                while (ladders && bricks < 0)
                {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                if (bricks < 0)
                    return i - 1;
            }
        }
        return n - 1;
    }
};
// @lc code=end

// Note: greedy + heap