/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */

// @lc code=start
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> hash;
        for (char c : s)
            hash[c]++;

        priority_queue<char> pq;
        for (auto &[ch, count] : hash)
            pq.push(ch);

        string ans;
        while (!pq.empty())
        {
            char ch = pq.top();
            pq.pop();
            int count = hash[ch];

            int use = min(count, repeatLimit);
            ans.append(use, ch);

            hash[ch] -= use;

            if (hash[ch] > 0 && !pq.empty())
            {
                char nextCh = pq.top();
                pq.pop();

                ans.push_back(nextCh);
                hash[nextCh]--;

                if (hash[nextCh] > 0)
                    pq.push(nextCh);

                pq.push(ch);
            }
        }

        return ans;
    }
};
// @lc code=end

// Note: hash table + heap + counting

// Official Solution