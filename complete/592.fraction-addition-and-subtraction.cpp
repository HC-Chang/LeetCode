/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start
class Solution
{
public:
    string fractionAddition(string expression)
    {
        int num = 0;
        int denom = 1;

        vector<string> nums;
        int i = 0;
        if (expression[0] != '-')
            expression = '+' + expression;
        while (i < expression.size())
        {
            int j = i + 1;
            while (j < expression.size() && expression[j] != '+' &&
                   expression[j] != '-')
                j++;

            nums.push_back(expression.substr(i, j - i));
            i = j;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            size_t pos = nums[i].find('/');
            int currNum = stoi(nums[i].substr(1, pos - 1));
            if (nums[i][0] == '-')
                currNum = -currNum;
            int currDenom = stoi(nums[i].substr(pos + 1));

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;

            int gcd = abs(find_gcd(num, denom));

            num /= gcd;
            denom /= gcd;
        }

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int find_gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return find_gcd(b % a, a);
    }
};
// @lc code=end

// Official Solution