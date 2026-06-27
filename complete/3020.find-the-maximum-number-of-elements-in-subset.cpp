/*
 * @lc app=leetcode id=3020 lang=cpp
 *
 * [3020] Find the Maximum Number of Elements in Subset
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        set<int> s;
        for (auto &n : nums)
        {
            ++hash[n];
            s.insert(n);
        }

        int ans = 0;
        for (auto &ss : s)
        {
            if (hash.find(ss) == hash.end() || hash[ss] == 0)
                continue;

            int tmp = 0;
            long long val = ss;
            while (hash.find(val) != hash.end() && hash[val] > 0)
            {
                if (hash[val] < 2)
                {
                    tmp++;
                    break;
                }

                tmp += 2;
                hash[val] -= 2;
                if (val * val > INT_MAX)
                    break;
                val *= val;
            }

            if (tmp > ans)
                ans = tmp;
        }

        if (ans % 2 == 0)
            ans--;
        return ans;
    }
};
// @lc code=end

// Note: hash table