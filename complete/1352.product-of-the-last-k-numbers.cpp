/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
class ProductOfNumbers
{
public:
    vector<int> v{1};
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
        {
            v.clear();
            v.push_back(1);
        }
        else
            v.push_back(num * v.back());
    }

    int getProduct(int k)
    {
        if (k >= v.size())
            return 0;
        return v.back() / v[v.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

// Note: math + prefix sum
