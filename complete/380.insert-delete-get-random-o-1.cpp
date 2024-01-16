/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet
{
public:
    unordered_map<int, int> map;
    vector<int> q;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;
        else
        {
            map[val] = q.size();
            q.push_back(val);
            return true;
        }
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;
        q[map[val]] = q.back();
        map[q.back()] = map[val];
        q.pop_back();
        map.erase(val);

        return true;
    }

    int getRandom()
    {
        int idx = rand() % q.size();
        return q[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

// Note: hash table