/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack
{
public:
    vector<int> arr;
    int capacity;
    CustomStack(int maxSize)
    {
        capacity = maxSize;
    }

    void push(int x)
    {
        if (arr.size() >= capacity)
            return;
        arr.push_back(x);
    }

    int pop()
    {
        if (arr.empty())
            return -1;
        int top = arr.back();
        arr.pop_back();
        return top;
    }

    void increment(int k, int val)
    {
        int cnt = fmin(k, arr.size());
        for (int i = 0; i < cnt; i++)
            arr[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

// Note: stack + design