/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        addInteger(nestedList);
    }

    int next()
    {
        const int num = stack.top().getInteger();
        stack.pop();
        return num;
    }

    bool hasNext()
    {
        while (!stack.empty() && !stack.top().isInteger())
        {
            vector<NestedInteger> nestedList = stack.top().getList();
            stack.pop();
            addInteger(nestedList);
        }
        return !stack.empty();
    }

private:
    stack<NestedInteger> stack;

    // addInteger([1, [4, [6]]]) -> stack = [[4, [6]], 1]
    // addInteger([4, [6]]) -> stack = [[6], 4]
    // addInteger([6]) -> stack = [6]
    void addInteger(const vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; --i)
            stack.push(nestedList[i]);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// @lc code=end

// Note: stack