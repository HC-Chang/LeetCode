/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
using puii = pair<unsigned int, int>;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<puii, vector<puii>, greater<puii>> busy;
        priority_queue<int, vector<int>, greater<int>> idle;
        for (int i = 0; i < n; i++)
            idle.push(i);

        vector<int> cnt(n);
        sort(meetings.begin(), meetings.end());

        int start;
        int end;
        int i;
        for (auto &v : meetings)
        {
            start = v[0];
            end = v[1];
            while (!busy.empty() && busy.top().first <= start)
            {
                idle.push(busy.top().second);
                busy.pop();
            }

            i = 0;
            if (!idle.empty())
            {
                i = idle.top();
                idle.pop();
                busy.push({end, i});
            }
            else
            {
                auto x = busy.top();
                busy.pop();
                i = x.second;
                busy.push({x.first + end - start, i});
            }
            ++cnt[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt[ans] < cnt[i])
                ans = i;
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + sorting + heap