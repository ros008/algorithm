#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    int len = new_id.length() > 15 ? 15 : new_id.length();
    for (int i = 0; i < len; i++)
    {
        if (new_id[i] == '.')
        {
            if (i == 0 || i == len - 1 || (i != 0 && new_id[i - 1] == '.'))
            {
                continue;
            }
            answer += new_id[i];
        }
        else if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            answer += (new_id[i] - 'A');
        }
        else if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_')
        {
            answer += new_id[i];
        }
    }
    if (answer.length() == 0)
        answer += "a";

    if (answer.length() <= 2)
    {
        int cur_len = answer.length();
        char last = answer[answer.length() - 1];
        for (int i = 0; i < 3 - cur_len; i++)
            answer += last;
    }

    return answer;
}

int main()
{
    string input;
    cin >> input;
    cout << solution(input);
    return 0;
}