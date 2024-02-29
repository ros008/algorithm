#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    int zeroCnt = 0, matchCnt = 0;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
            zeroCnt++;
        else
        {
            for (int j = 0; j < win_nums.size(); j++)
            {
                if (lottos[i] == win_nums[j])
                {
                    matchCnt++;
                    break;
                }
            }
        }
    }

    if (zeroCnt + matchCnt >= 2)
        answer.push_back(7 - (zeroCnt + matchCnt));
    else
        answer.push_back(6);

    if (matchCnt >= 2)
        answer.push_back(7 - matchCnt);
    else
        answer.push_back(6);

    return answer;
}

int main()
{
    vector<int> lottos = {44, 1, 0, 0, 31, 25};
    vector<int> win_nums = {31, 10, 45, 1, 6, 19};

    vector<int> ans = solution(lottos, win_nums);
    cout << ans[0] << " " << ans[1];

    return 0;
}