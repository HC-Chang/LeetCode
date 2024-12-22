/*
 * @lc app=leetcode id=2940 lang=cpp
 *
 * [2940] Find Building Where Alice and Bob Can Meet
 */

// @lc code=start
class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        vector<vector<vector<int>>> store_queries(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> max_index;
        vector<int> result(queries.size(), -1);

        for (int currQuery = 0; currQuery < queries.size(); currQuery++)
        {
            int a = queries[currQuery][0], b = queries[currQuery][1];
            if (a < b && heights[a] < heights[b])
                result[currQuery] = b;
            else if (a > b && heights[a] > heights[b])
                result[currQuery] = a;
            else if (a == b)
                result[currQuery] = a;
            else
                store_queries[max(a, b)].push_back({max(heights[a], heights[b]), currQuery});
        }

        for (int index = 0; index < heights.size(); index++)
        {
            while (!max_index.empty() && max_index.top()[0] < heights[index])
            {
                result[max_index.top()[1]] = index;
                max_index.pop();
            }

            for (auto &element : store_queries[index])
                max_index.push(element);
        }
        return result;
    }
};
// @lc code=end

// Note: heap

// Official Solution