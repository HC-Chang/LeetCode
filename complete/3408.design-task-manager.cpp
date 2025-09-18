/*
 * @lc app=leetcode id=3408 lang=cpp
 *
 * [3408] Design Task Manager
 */

// @lc code=start
class TaskManager
{
public:
    priority_queue<pair<int, int>> tasks;
    unordered_map<int, int> map_t_u;
    unordered_map<int, int> map_t_p;
    TaskManager(vector<vector<int>> & tasks)
    {
        for (auto t : tasks)
            add(t[0], t[1], t[2]);
    }

    void add(int userId, int taskId, int priority)
    {
        tasks.push({priority, taskId});
        map_t_u[taskId] = userId;
        map_t_p[taskId] = priority;
    }

    void edit(int taskId, int newPriority)
    {
        tasks.push({newPriority, taskId});
        map_t_p[taskId] = newPriority;
    }

    void rmv(int taskId) { map_t_p[taskId] = -1; }

    int execTop()
    {
        while (!tasks.empty())
        {
            const auto task = tasks.top();
            tasks.pop();
            if (task.first == map_t_p[task.second])
            {
                map_t_p[task.second] = -1;
                return map_t_u[task.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
// @lc code=end

// Note: hash map + priority queue

// Official Solution
