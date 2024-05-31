/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
// Solution 2:

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xor2no = 0;
        for (auto i : nums)
            xor2no ^= i;

        unsigned int lowestBit = xor2no & -(unsigned int)xor2no;

        vector<int> ans(2);
        for (auto i : nums)
        {
            if ((lowestBit & i) == 0)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }

        return ans;
    }
};
// @lc code=end

// Note: bit manipulation

// Solution 1:

// class Solution
// {
// public:
//     vector<int> singleNumber(vector<int> &nums)
//     {
//         unordered_map<int, int> hash;
//         for (auto i : nums)
//         {
//             hash[i]++;
//             if (hash[i] == 2)
//                 hash.erase(i);
//         }

//         vector<int> ans;
//         for (auto kv : hash)
//             ans.push_back(kv.first);

//         return ans;
//     }
// };