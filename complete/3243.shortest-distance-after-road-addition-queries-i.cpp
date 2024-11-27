/*
 * @lc app=leetcode id=3243 lang=cpp
 *
 * [3243] Shortest Distance After Road Addition Queries I
 */

// @lc code=start
class Solution
{
public:
    int find_min_dis(vector<vector<int>> &adj_list, int n)
    {
        vector<int> dp(n);
        dp[n - 1] = 0;

        for (int currentNode = n - 2; currentNode >= 0; currentNode--)
        {
            int minDistance = n;
            for (auto neighbor : adj_list[currentNode])
                minDistance = min(minDistance, dp[neighbor] + 1);

            dp[currentNode] = minDistance;
        }
        return dp[0];
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries)
    {
        vector<int> answer;
        vector<vector<int>> adj_list(n, vector<int>(0));

        for (int i = 0; i < n - 1; i++)
            adj_list[i].push_back(i + 1);

        for (auto &road : queries)
        {
            adj_list[road[0]].push_back(road[1]);

            answer.push_back(find_min_dis(adj_list, n));
        }
        return answer;
    }
};
// @lc code=end

// Note: BFS

// Official Solution