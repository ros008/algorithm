#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int total_time = 0;

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    int cur_time = 0;
    int jobs_cnt = 0;

    sort(jobs.begin(), jobs.end());

    while (jobs_cnt < jobs.size() || !pq.empty())
    {
        if (jobs_cnt < jobs.size() && jobs[jobs_cnt][0] <= cur_time)
        {
            pq.push(jobs[jobs_cnt++]);
            continue;
        }

        if (!pq.empty())
        {
            cur_time += pq.top()[1];
            total_time += (cur_time - pq.top()[0]);
            pq.pop();
        }
        else
        {
            cur_time = jobs[jobs_cnt][0];
        }
    }
    answer = total_time / jobs.size();
    return answer;
}

int main()
{
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};

    cout << solution(jobs) << "\n";

    return 0;
}