#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 360001

int convertTimeStringToInt(string str)
{
    int ret = 0;
    string sec_str = str.substr(6, 2);
    int sec = stoi(sec_str);
    string min_str = str.substr(3, 2);
    int min = stoi(min_str) * 60;
    string hour_str = str.substr(0, 2);
    int hour = stoi(hour_str) * 60 * 60;
    ret = hour + min + sec;
    return ret;
}

string convertTimeIntToString(int num)
{
    string ret = "";
    int hour = num / 3600;
    int min = (num % 3600) / 60;
    int sec = num % 60;

    if (hour <= 9)
        ret += '0';
    ret += to_string(hour);
    ret += ':';
    if (min <= 9)
        ret += '0';
    ret += to_string(min);
    ret += ':';
    if (sec <= 9)
        ret += '0';
    ret += to_string(sec);
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";

    int play_time_sec = convertTimeStringToInt(play_time);
    int adv_time_sec = convertTimeStringToInt(adv_time);
    vector<int> total_time(360001, 0);

    for (int i = 0; i < logs.size(); i++)
    {
        int start_time = convertTimeStringToInt(logs[i].substr(0, 8));
        int end_time = convertTimeStringToInt(logs[i].substr(9, 8));
        for (int j = start_time; j < end_time; j++)
        {
            total_time[j]++;
        }
    }

    long long max_play_cnt = 0;
    long long cur_play_cnt = 0;
    int max_time_start = 0;

    for (int i = 0; i < adv_time_sec; i++)
        max_play_cnt += total_time[i];

    cur_play_cnt = max_play_cnt;

    for (int i = adv_time_sec; i < play_time_sec; i++)
    {
        cur_play_cnt += (long long)(total_time[i] - total_time[i - adv_time_sec]);
        if (cur_play_cnt > max_play_cnt)
        {
            max_play_cnt = cur_play_cnt;
            max_time_start = i - adv_time_sec + 1;
        }
    }
    answer = convertTimeIntToString(max_time_start);

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