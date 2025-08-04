/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
// Solution 2
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        if (n <= 2)
            return n;
        int total = 0;
        int vals[2];
        for (int i = 0; i < n - 1; i++)
        {
            vals[0] = fruits[i];
            int j = i + 1;
            while (j + 1 < n && fruits[j] == vals[0])
                j++;
            vals[1] = fruits[j];

            while (j + 1 < n &&
                   (fruits[j + 1] == vals[0] || fruits[j + 1] == vals[1]))
                j++;
            total = max(total, j - i + 1);
            if (total > n / 2)
                break;
        }

        return total;
    }
};
// @lc code=end

// Note: hash table + sliding window

// Solution1: Official Solution - Sliding Window

// class Solution
// {
// public:
//     int totalFruit(vector<int> &fruits)
//     {
//         // We use a hash map 'basket' to store the number of each type of fruit.
//         unordered_map<int, int> basket;
//         int left = 0, maxPicked = 0;

//         // Add fruit from the right index (right) of the window.
//         for (int right = 0; right < fruits.size(); ++right)
//         {
//             basket[fruits[right]]++;

//             // If the current window has more than 2 types of fruit,
//             // we remove fruit from the left index (left) of the window,
//             // until the window has only 2 types of fruit.
//             while (basket.size() > 2)
//             {
//                 basket[fruits[left]]--;
//                 if (basket[fruits[left]] == 0)
//                     basket.erase(fruits[left]);
//                 left++;
//             }

//             // Update maxPicked.
//             maxPicked = max(maxPicked, right - left + 1);
//         }

//         // Return maxPicked as the maximum number of fruits we can collect.
//         return maxPicked;
//     }
// }
// ;