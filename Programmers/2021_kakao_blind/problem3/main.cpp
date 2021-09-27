#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    map<string, vector<int>> m;

    for (int i = 0; i < info.size(); i++)
    {
        vector<vector<string>> v(4, vector<string>(2, "-"));
        int score = 0;

        istringstream stream(info[i]);
        stream >> v[0][1] >> v[1][1] >> v[2][1] >> v[3][1] >> score;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        string str = v[0][i] + v[1][j] + v[2][k] + v[3][l];
                        m[str].push_back(score);
                    }
                }
            }
        }
    }

    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        sort(itr->second.begin(), itr->second.end());
    }

    for (int i = 0; i < query.size(); i++)
    {
        string str[4], tmp;
        int score = 0;
        istringstream stream(query[i]);
        stream >> str[0] >> tmp >> str[1] >> tmp >> str[2] >> tmp >> str[3] >> score;

        vector<int> scores = m[str[0] + str[1] + str[2] + str[3]];
        int cnt = scores.end() - lower_bound(scores.begin(), scores.end(), score);
        answer.push_back(cnt);
    }

    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"};

    solution(info, query);

    int num;
    string s;
    string str1 = "123 456", str2 = "hello world", str3 = "abc def gg 11";
    stringstream stream1, stream2(str2);
    string s2[4];
    istringstream stt(str3);

    stream1.str(str1);
    while (stream1 >> num)
    {
        cout << num << "\n";
    }

    while (stream2 >> s)
    {
        cout << s << "\n";
    }

    stt >> s2[0] >> s2[1] >> s2[2] >> s2[3];

    cout << s2[0] << "\n";
    cout << s2[1] << "\n";
    cout << s2[2] << "\n";
    cout << s2[3] << "\n";

    return 0;
}