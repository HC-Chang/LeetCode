/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar
{
public:
    vector<pair<int, int>> booking;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (auto b : booking)
        {
            if (max(b.first, start) < min(b.second, end))
                return false;
        }
        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

// Note: segment tree