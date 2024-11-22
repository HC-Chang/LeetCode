/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> patternFrequency;

        for (auto &currentRow : matrix)
        {
            string patternBuilder = "";

            for (int col = 0; col < currentRow.size(); col++)
            {
                if (currentRow[0] == currentRow[col])
                    patternBuilder += "T";
                else
                    patternBuilder += "F";
            }

            patternFrequency[patternBuilder]++;
        }

        int maxFrequency = 0;
        for (auto &entry : patternFrequency)
            maxFrequency = max(entry.second, maxFrequency);

        return maxFrequency;
    }
};
// @lc code=end

// Note: hash table + matrix

// Official Solution