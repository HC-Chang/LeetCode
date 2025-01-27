/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        unordered_map<int, vector<int>> hash;
        vector<int> indegree(numCourses);
        for (auto p : prerequisites)
        {
            hash[p[0]].push_back(p[1]);
            ++indegree[p[1]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto adj : hash[node])
            {
                nodePrerequisites[adj].insert(node);
                for (auto prereq : nodePrerequisites[node])
                    nodePrerequisites[adj].insert(prereq);

                indegree[adj]--;
                if (!indegree[adj])
                    q.push(adj);
            }
        }
        vector<bool> ans;
        for (auto q : queries)
            ans.push_back(nodePrerequisites[q[1]].contains(q[0]));

        return ans;
    }
};
// @lc code=end

// Note: topological sort

// Official Solution