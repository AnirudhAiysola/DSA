class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        queue<int> q;
        unordered_map<int, int> m;

        for (auto it : students)
        {
            m[it]++;
            q.push(it);
        }
        for (int i = 0; i < n; i++)
        {
            if (!m.count(sandwiches[i]))
            {
                return n - i;
            }
            while (!q.empty() && q.front() != sandwiches[i])
            {
                int student = q.front();
                q.pop();
                q.push(student);
            }
            q.pop();
            m[sandwiches[i]]--;
            if (m[sandwiches[i]] == 0)
                m.erase(sandwiches[i]);
        }
        return 0;
    }
};