/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution
{
public:
    const vector<int> split(string &str, const char &delimiter)
    {
        vector<int> result;
        stringstream ss(str);
        string tok;

        while (getline(ss, tok, delimiter))
        {
            result.push_back(stoi(tok));
        }
        return result;
    }

    int compareVersion(string version1, string version2)
    {
        vector<int> arr1 = split(version1, '.');
        vector<int> arr2 = split(version2, '.');

        for (int i = 0; i < max(arr1.size(), arr2.size()); i++)
        {
            int v1 = i < arr1.size() ? arr1[i] : 0;
            int v2 = i < arr2.size() ? arr2[i] : 0;
            if (v1 != v2)
                return v1 < v2 ? -1 : 1;
        }

        return 0;
    }
};
// @lc code=end

// Note: two pointers / stack