/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution
{
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string &curr)
    {
        while (vec.count(curr) && vec[curr].size() > 0)
        {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto &it : tickets)
        {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};
// @lc code=end

// Official Solution

// Note: DFS . graph . Eulerian Circuit