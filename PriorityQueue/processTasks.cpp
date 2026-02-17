#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Assigns tasks to servers based on their weights and availability.
 * 
 * This class provides a solution for the task assignment problem where tasks
 * must be assigned to available servers. Each server has a weight, and each
 * task requires a certain amount of time to complete. Tasks are assigned in
 * order to the lightest available server at the time of assignment.
 * 
 * @method assignTasks
 * @param servers - A vector of integers representing the weight of each server.
 *                  Lower weight values indicate more preferred servers.
 * @param tasks - A vector of integers representing the time required to
 *                complete each task in order.
 * 
 * @return A vector of integers where result[i] represents the index of the
 *         server assigned to task i.
 * 
 * @complexity
 *   Time: O((n + m) * log n) where n is the number of servers and m is the
 *         number of tasks. Each task may trigger server state changes and
 *         priority queue operations.
 *   Space: O(n) for storing servers in the priority queues.
 * 
 * @note The algorithm uses two priority queues:
 *       1. `free` - maintains available servers sorted by weight (min-heap)
 *       2. `busy` - maintains busy servers sorted by completion time (min-heap)
 *       
 *       When a task arrives, the earliest completing server from `busy` is
 *       moved to `free` if its completion time has been reached. If free
 *       servers are available, the task is assigned to the lightest one.
 *       Otherwise, the earliest completing server is reassigned after it finishes.
 */
class Solution
{
public:
    typedef long long ll;
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        int n = servers.size();
        int m = tasks.size();

        /*
        server[i] -> weight of ith server
        tasks[j] -> time taken to finish this task
        */
        typedef pair<ll, ll> p;

        priority_queue<p, vector<p>, greater<>> free;
        priority_queue<pair<ll, p>, vector<pair<ll, p>>, greater<>> busy;

        for (int i = 0; i < n; i++)
        {
            free.push({servers[i], i});
        }
        vector<int> result;
        int time = 0;

        for (int i = 0; i < m; i++)
        {
            // check if server becomes free
            while (!busy.empty() && busy.top().first <= time)
            {
                free.push(busy.top().second);
                busy.pop();
            }
            if (!free.empty())
            {
                auto [wt, idx] = free.top();
                free.pop();
                result.push_back(idx);
                busy.push({time + (ll)tasks[i], {wt, idx}});
            }
            else
            {
                auto data = busy.top();
                busy.pop();
                ll diff = data.first - time;
                result.push_back(data.second.second);
                busy.push({time + diff + (ll)tasks[i], {data.second.first, data.second.second}});
            }
            time++;
        }
        return result;
    }
};