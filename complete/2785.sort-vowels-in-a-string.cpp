/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
class Solution
{
public:
    string sortVowels(string s)
    {
        vector<char> arr;
        vector<int> index;
        
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                index.push_back(i);
                arr.push_back(s[i]);
                break;
            }
        }

        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
            s[index[i]] = arr[i];
        return s;
    }
};
// @lc code=end

// Note: sorting