/*
 * @lc app=leetcode id=3508 lang=cpp
 *
 * [3508] Find Closest Person
 */

// @lc code=start
class Router {
public:
    deque<vector<int>> dv;
    set<tuple<int,int,int>> s;
    unordered_map<int, deque<int>> dt;

    int limit = 0;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(s.find({ source,  destination, timestamp}) != s.end())
            return false;
        if(dv.size() >= limit)
        {
            dt[dv.front()[1]].pop_front();
            s.erase(s.find({dv.front()[0],dv.front()[1],dv.front()[2]}));
            dv.pop_front();
        }
        s.insert({ source,  destination, timestamp});
        dv.push_back({ source,  destination, timestamp});
        dt[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dv.size() == 0)
            return {};
        vector<int> r = {dv[0][0],dv[0][1],dv[0][2]};

        auto &arr = dt[dv.front()[1]];
        auto it = lower_bound(arr.begin(), arr.end(), dv.front()[2]);
        if (it != arr.end() && *it == dv.front()[2])
            arr.erase(it); 

        s.erase(s.find({dv.front()[0],dv.front()[1],dv.front()[2]}));
        dv.pop_front();
        return r;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &arr = dt[destination];
        auto l = lower_bound(arr.begin(), arr.end(), startTime);
        auto r = upper_bound(arr.begin(), arr.end(), endTime);
        return r-l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
// @lc code=end

// Note: hash table + queue + binary search + design
