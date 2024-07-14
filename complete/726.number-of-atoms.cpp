/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int i = 0;
        int n = formula.length();

        auto parseAtom = [&]() -> string
        {
            string atom;
            atom += formula[i++];
            while (i < n && islower(formula[i]))
            {
                atom += formula[i++];
            }
            return atom;
        };

        auto parseNum = [&]() -> int
        {
            if (i == n || !isdigit(formula[i]))
                return 1;

            int num = 0;
            while (i < n && isdigit(formula[i]))
                num = num * 10 + int(formula[i++] - '0');

            return num;
        };

        stack<unordered_map<string, int>> s_hash;
        s_hash.push({});
        while (i < n)
        {
            char ch = formula[i];
            if (ch == '(')
            {
                i++;
                s_hash.push({});
            }
            else if (ch == ')')
            {
                i++;
                int num = parseNum();
                auto atomNum = s_hash.top();
                s_hash.pop();
                for (auto &[atom, v] : atomNum)
                    s_hash.top()[atom] += v * num;
            }
            else
            {
                string atom = parseAtom();
                int num = parseNum();
                s_hash.top()[atom] += num;
            }
        }

        auto &atomNum = s_hash.top();
        vector<pair<string, int>> pairs;
        for (auto &[atom, v] : atomNum)
            pairs.emplace_back(atom, v);

        sort(pairs.begin(), pairs.end());

        string ans;
        for (auto &p : pairs)
        {
            ans += p.first;
            if (p.second > 1)
                ans += to_string(p.second);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table + stack + sorting

// Official Solution