/*
 * @lc app=leetcode id=2751 lang=cpp
 *
 * [2751] Robot Collisions
 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int i;
        int p;
        int h;
        char d;
    } ROBOT;

    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths, string directions)
    {
        vector<int> ans;
        vector<ROBOT> robots;
        vector<ROBOT> stack;

        for (int i = 0; i < positions.size(); ++i)
            robots.push_back(ROBOT{i, positions[i], healths[i], directions[i]});

        sort(robots.begin(), robots.end(),
             [](const ROBOT &a, const ROBOT &b)
             { return a.p < b.p; });

        for (ROBOT &robot : robots)
        {
            if (robot.d == 'R')
            {
                stack.push_back(robot);
                continue;
            }
            while (!stack.empty() && stack.back().d == 'R' && robot.h > 0)
            {
                if (stack.back().h == robot.h)
                {
                    stack.pop_back();
                    robot.h = 0;
                }
                else if (stack.back().h < robot.h)
                {
                    stack.pop_back();
                    robot.h -= 1;
                }
                else
                {
                    stack.back().h -= 1;
                    robot.h = 0;
                }
            }
            if (robot.h > 0)
                stack.push_back(robot);
        }

        sort(stack.begin(), stack.end(),
             [](const ROBOT &a, const ROBOT &b)
             { return a.i < b.i; });

        for (const ROBOT &robot : stack)
            ans.push_back(robot.h);

        return ans;
    }
};
// @lc code=end

// Note: stack + sorting