/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        int fizz = 3;
        int buzz = 5;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == fizz && i + 1 == buzz)
            {
                ans.push_back("FizzBuzz");
                fizz += 3;
                buzz += 5;
            }
            else if (i + 1 == fizz)
            {
                ans.push_back("Fizz");
                fizz += 3;
            }
            else if (i + 1 == buzz)
            {
                ans.push_back("Buzz");
                buzz += 5;
            }
            else
                ans.push_back(to_string(i + 1));
        }

        return ans;
    }
};
// @lc code=end
