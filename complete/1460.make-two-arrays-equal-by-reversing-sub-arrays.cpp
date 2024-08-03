/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> hash;
        for (int a : arr)
            hash[a]++;

        for (int t : target)
        {
            if (hash.find(t) == hash.end())
                return false;

            hash[t]--;
            if (hash[t] == 0)
                hash.erase(t);
        }
        return hash.size() == 0;
    }
};
// @lc code=end

// Note: hash table