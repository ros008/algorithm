#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";

    return answer;
}

int main()
{
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};

    cout << solution(play_time, adv_time, logs);

    return 0;
}