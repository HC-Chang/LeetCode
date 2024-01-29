/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    void s1_to_s2()
    {
        while (!s1.empty())
        {
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
    }

    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int result = -1;

        if (s2.empty())
            s1_to_s2();

        result = s2.top();
        s2.pop();
        if (s2.empty())
            s1_to_s2();
        return result;
    }

    int peek()
    {
        if (s2.empty())
            s1_to_s2();
        return s2.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

// stack api:
// - push
// - pop
// - top
// - is_empty
// - free (optional)

// Note: design