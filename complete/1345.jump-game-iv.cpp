/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int>> m;
        int N = arr.size(), step = 0;
        for (int i = 0; i < N; ++i)
            m[arr[i]].push_back(i);
        vector<bool> visited(N);
        visited[0] = true;
        queue<int> q{{0}};
        while (q.size())
        {
            int cnt = q.size();
            while (cnt--)
            {
                int u = q.front();
                q.pop();
                if (u == N - 1)
                    return step;
                if (u - 1 >= 0 && !visited[u - 1])
                {
                    q.push(u - 1);
                    visited[u - 1] = true;
                }
                if (u + 1 < N && !visited[u + 1])
                {
                    q.push(u + 1);
                    visited[u + 1] = true;
                }
                if (m.count(arr[u]))
                {
                    for (int v : m[arr[u]])
                    {
                        if (visited[v])
                            continue;
                        visited[v] = true;
                        q.push(v);
                    }
                    m.erase(arr[u]);
                }
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end

// ref: github.com/lzl124631x
// https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1345.%20Jump%20Game%20IV