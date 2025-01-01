/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> arr(numCourses, vector<int>());
        vector<int> cnts(numCourses);
        for (auto p : prerequisites)
        {
            arr[p[1]].push_back(p[0]);
            ++cnts[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!cnts[i])
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int len_q = q.size();
            numCourses -= len_q;

            for (int i = 0; i < len_q; i++)
            {
                ans.emplace_back(q.front());

                for (auto next_val : arr[q.front()])
                {
                    if (cnts[next_val]-- == 1)
                        q.push(next_val);
                }
                q.pop();
            }
        }

        if (!numCourses)
            return ans;
        return {};
    }
};
// @lc code=end

// Note: Topological Sort