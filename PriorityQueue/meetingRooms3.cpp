class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        int m = meetings.size();
        // sort accoring to start time of the meetings
        sort(meetings.begin(), meetings.end());

        vector<int> roomsFreq(n, 0);
        priority_queue<long long, vector<long long>, greater<long long>> available;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> inUse;
        // push all the rooms into available
        for (int i = 0; i < n; i++)
        {
            available.push(i);
        }
        for (int i = 0; i < m; i++)
        {
            long long currStartTime = meetings[i][0];
            long long currEndTime = meetings[i][1];
            // check if any meetings are ending at current start time
            while (!inUse.empty() && inUse.top().first <= currStartTime)
            {
                available.push(inUse.top().second);
                inUse.pop();
            }
            // check if all rooms are occupied
            if (available.empty())
            {
                long long availableRoomTime = inUse.top().first;
                long long roomNumber = inUse.top().second;
                inUse.pop();
                long long delay = availableRoomTime - currStartTime;
                inUse.push({currEndTime + delay, roomNumber});
                roomsFreq[roomNumber]++;
            }
            else
            {
                long long room = available.top();
                available.pop();
                inUse.push({currEndTime, room});
                roomsFreq[room]++;
            }
        }
        int result = -1;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (roomsFreq[i] > curr)
            {
                result = i;
                curr = roomsFreq[i];
            }
        }
        return result;
    }
};