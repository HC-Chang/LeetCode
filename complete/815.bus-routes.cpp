/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
        return 0;
    
    vector<bool>visited_routes(100001, false);
    vector<int>hash(100001, -1);
    
    int size = routes.size();
    for (int i = 0; i < routes.size(); i++)
    {
        for (int j = 0; j < routes[i].size(); j++)
        {
            if (routes[i][j] == source)
            {
                visited_routes[i] = true;
                size--;
                for (j = 0; j < routes[i].size(); j++)
                    hash[routes[i][j]] = 1;
                break;
            }
        }
    }
    if (size == routes.size())
        return -1;
    if (hash[target] != -1)
        return hash[target];
    bool flag;
    while (size > 0)
    {
        flag = false;
        for (int i = 0; i < routes.size(); i++)
        {
            if (visited_routes[i] == true)
                continue;
            int mmin = INT_MAX;
            for (int j = 0; j < routes[i].size(); j++)
            {
                if (hash[routes[i][j]] != -1)
                    mmin = min(mmin, hash[routes[i][j]]);
            }
            if (mmin != INT_MAX)
            {
                flag = true;
                visited_routes[i] = true;
                size--;
                for (int j = 0; j < routes[i].size(); j++)
                {
                    if (hash[routes[i][j]] == -1)
                        hash[routes[i][j]] = mmin + 1;
                }
            }
            if (hash[target] != -1 || size <= 0)
                break;
        }
        if (hash[target] != -1 || size <= 0 || !flag)
            break;
    }
    return hash[target];
    }
};
// @lc code=end

// Official Solution