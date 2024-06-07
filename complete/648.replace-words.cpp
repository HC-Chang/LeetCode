/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        vector<string> dics[26];
        for (auto d : dictionary)
            dics[d[0] - 'a'].push_back(d);
        for (int i = 0; i < 26; i++)
            sort(dics[i].begin(), dics[i].end());

        vector<string> s;
        int n = sentence.size();
        int start = 0;
        int cnt = 0;
        for (int i = 0; i < n && start < n; i++)
        {
            if (sentence[i] != ' ')
                cnt++;
            else
            {
                s.push_back(sentence.substr(start, cnt));
                start = i + 1;
                cnt = 0;
            }
        }
        s.push_back(sentence.substr(start, cnt));

        sentence.clear();
        int trigger;
        for (auto ss : s)
        {
            if (dics[ss[0] - 'a'].size() == 0)
                sentence += ss + ' ';
            else
            {
                trigger = 0;
                for (auto d : dics[ss[0] - 'a'])
                {
                    if (d == ss.substr(0, d.size()))
                    {
                        sentence += d + ' ';
                        trigger = 1;
                        break;
                    }
                }
                if (!trigger)
                    sentence += ss + ' ';
            }
        }
        sentence.pop_back();

        return sentence;
    }
};
// @lc code=end

// Note: hash table / trie