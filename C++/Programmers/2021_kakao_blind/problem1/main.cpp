#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    // step 1
    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = tolower(new_id[i]);
        }
    }

    // step 2
    for (int i = 0; i < new_id.length(); i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            answer.push_back(new_id[i]);
        }
    }

    // step 3
    int i = 1;
    while (i < answer.length())
    {
        if (answer[i - 1] == '.' && answer[i] == '.')
        {
            answer.erase(answer.begin() + i);
        }
        else
        {
            i++;
        }
    }

    // step 4
    if (answer[0] == '.')
        answer.erase(answer.begin());
    if (answer[answer.length() - 1] == '.')
        answer.erase(answer.end() - 1);

    // step 5
    if (answer.length() == 0)
        answer.push_back('a');

    // step 6
    if (answer.length() > 15)
    {
        answer.erase(answer.begin() + 15, answer.end());
        if (answer[answer.length() - 1] == '.')
        {
            answer.erase(answer.end() - 1);
        }
    }

    // step 7
    while (answer.length() <= 2)
    {
        answer.push_back(answer[answer.length() - 1]);
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