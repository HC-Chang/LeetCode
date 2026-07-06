/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution
{
    unordered_map<string, vector<pair<string, double>>> g;

    bool dfs(const string &u, const string &target, unordered_set<string> &vis, double &acc)
    {
        if (u == target)
            return true;
        vis.insert(u);
        for (auto &p : g[u])
        {
            if (vis.count(p.first))
                continue;
            double prev = acc;
            acc *= p.second;
            if (dfs(p.first, target, vis, acc))
                return true;
            acc = prev;
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        g.clear();
        for (size_t i = 0; i < equations.size(); ++i)
        {
            const string &a = equations[i][0];
            const string &b = equations[i][1];
            double w = values[i];
            g[a].push_back({b, w});
            g[b].push_back({a, 1.0 / w});
        }

        vector<double> res;
        res.reserve(queries.size());
        for (auto &q : queries)
        {
            const string &s = q[0];
            const string &t = q[1];
            if (!g.count(s) || !g.count(t))
            {
                res.push_back(-1.0);
                continue;
            }
            if (s == t)
            {
                res.push_back(1.0);
                continue;
            }
            unordered_set<string> vis;
            double acc = 1.0;
            bool found = dfs(s, t, vis, acc);
            res.push_back(found ? acc : -1.0);
        }
        return res;
    }
};
// @lc code=end
