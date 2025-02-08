/*
 * @lc app=leetcode id=2349 lang=cpp
 *
 * [2349] Design a Number Container System
 */

// @lc code=start
class NumberContainers
{
public:
    unordered_map<int, int> hash;
    unordered_map<int, set<int>> set;
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (hash.contains(index))
        {
            int last_number = hash[index];
            set[last_number].erase(index);
            if (set[last_number].empty())
            {
                set.erase(last_number);
            }
        }
        hash[index] = number;
        set[number].insert(index);
    }

    int find(int number)
    {
        return set.contains(number) ? *set[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end

// Note: hash table + heap + ordered set

// Official Solution