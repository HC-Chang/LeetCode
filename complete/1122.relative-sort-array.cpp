/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> hash;
        for (auto i : arr1)
            ++hash[i];

        arr1.clear();
        for (auto i : arr2)
        {
            if (hash.find(i) != hash.end())
            {
                for (int j = 0; j < hash[i]; j++)
                    arr1.push_back(i);
                hash.erase(i);
            }
        }

        vector<pair<int, int>> vec(hash.begin(), hash.end());
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
             { return b.first > a.first; });

        for (auto i : vec)
        {
            for (int j = 0; j < i.second; j++)
                arr1.push_back(i.first);
        }

        return arr1;
    }
};
// @lc code=end

// Note: hash table