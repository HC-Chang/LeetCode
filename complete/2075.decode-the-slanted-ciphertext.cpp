/*
 * @lc app=leetcode id=2075 lang=cpp
 *
 * [2075] Decode the Slanted Ciphertext
 */

// @lc code=start
class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        if (rows == 1)
            return encodedText;
        int n = encodedText.size() / rows;
        string ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (j * n + i + j >= encodedText.size())
                    break;
                ans += encodedText[j * n + i + j];
            }
        }
        ans.erase(ans.find_last_not_of(" \n\r\t") + 1);
        return ans;
    }
};
// @lc code=end
