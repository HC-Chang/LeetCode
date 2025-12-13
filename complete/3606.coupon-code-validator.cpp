/*
 * @lc app=leetcode id=3606 lang=cpp
 *
 * [3606] Coupon Code Validator
 */

// @lc code=start
class Solution
{
public:
    bool check_code(string code)
    {
        if (code == "")
            return false;
        for (auto &c : code)
        {
            if (!(c <= 'z' && c >= 'a') && !(c <= 'Z' && c >= 'A') && !(c <= '9' && c >= '0') && !(c == '_'))
                return false;
        }
        return true;
    }
    bool check_business(string code)
    {
        if (code == "electronics" || code == "grocery" || code == "pharmacy" || code == "restaurant")
            return true;
        return false;
    }
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        int n = code.size();
        vector<pair<string, string>> p;
        for (int i = 0; i < n; i++)
        {
            if (isActive[i] && check_code(code[i]) && check_business(businessLine[i]))
                p.push_back(make_pair(businessLine[i], code[i]));
        }

        sort(p.begin(), p.end(), [](const std::pair<string, string> &a, const std::pair<string, string> &b)
             {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first; });

        vector<string> ans;
        for (const auto &pp : p)
            ans.push_back(pp.second);

        return ans;
    }
};
// @lc code=end
