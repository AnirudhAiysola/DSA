class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        queue<pair<int, int>> q;
        int time = 0;
        for (int i = 0; i < n; i++)
        {
            q.push({i, tickets[i]});
        }
        while (!q.empty())
        {
            int person = q.front().first;
            int ticket = q.front().second;
            q.pop();
            ticket--;
            time++;
            if (person == k && ticket == 0)
            {
                return time;
            }
            if (ticket != 0)
                q.push({person, ticket});
        }
        return time;
    }
};