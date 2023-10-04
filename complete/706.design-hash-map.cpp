/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start

class MyHashMap
{
public:
    MyHashMap()
    {
        arr.resize(1001, vector<int>());
    }

    void put(int key, int value)
    {
        int hashKey = key % 1000;
        if (arr[hashKey].empty())
            arr[hashKey].resize(1001, -1);

        arr[hashKey][key / 1000] = value;
    }

    int get(int key)
    {
        int hashKey = key % 1000;
        if (!arr[hashKey].empty())
            return arr[hashKey][key / 1000];
        return -1;
    }

    void remove(int key)
    {
        int hashKey = key % 1000;
        if (!arr[hashKey].empty())
            arr[hashKey][key / 1000] = -1;
    }

private:
    vector<vector<int>> arr;
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
