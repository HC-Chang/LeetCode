/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
// Solution 2: sorting
class Solution
{
public:
    string sorted_str_from_val(int val)
    {
        string s = to_string(val);
        sort(s.begin(), s.end());
        return s;
    }

    bool reorderedPowerOf2(int n)
    {
        string sort_n = sorted_str_from_val(n);
        for (int i = 0; i < 31; ++i)
        {
            if (sorted_str_from_val(1 << i) == sort_n)
                return true;
        }
        return false;
    }
};
// @lc code=end

// Solution 1: hash table

// #include <climits>

// class Solution {
// public:
//     unordered_map<int, int> get_hash_from_val(int val) {
//         unordered_map<int, int> hash;
//         while (val > 0) {
//             ++hash[val % 10];
//             val /= 10;
//         }
//         return hash;
//     }

//     bool reorderedPowerOf2(int n) {
//         if (n == 1)
//             return true;

//         unordered_map<int, int> s = get_hash_from_val(n);
//         unsigned long long upper_bound = pow(10, to_string(n).length());
//         unsigned long long pow_val = 2;
//         while (pow_val <= upper_bound) {
//             unordered_map<int, int> tmp = get_hash_from_val(pow_val);
//             if (tmp == s)
//                 return true;
//             pow_val *= 2;
//         }

//         return false;
//     }
// };