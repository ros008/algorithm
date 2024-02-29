#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> dict;

void dfs(string order, string comb, int pos, int depth)
{
    if (comb.size() == depth)
    {
        dict[comb]++;
        return;
    }
    for (int i = pos; i < order.length(); i++)
    {
        dfs(order, comb + order[i], i + 1, depth);
    }
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<string, int> dic;

    for (int i = 0; i < course.size(); i++)
    {
        dict.clear();
        for (int j = 0; j < orders.size(); j++)
        {
            sort(orders[j].begin(), orders[j].end());
            if (course[i] <= orders[j].length())
                dfs(orders[j], "", 0, course[i]);
        }

        vector<pair<string, int>> v(dict.begin(), dict.end());
        sort(v.begin(), v.end(), cmp);

        int biggest = v.begin()->second;
        if (biggest >= 2)
        {
            for (auto it = v.begin(); it != v.end(); ++it)
            {
                if (it->second == biggest)
                {
                    answer.push_back(it->first);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    for (auto it = answer.begin(); it != answer.end(); ++it)
        cout << *it << ' ';

    return answer;
}

int main()
{
    vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course = {2, 3, 5};

    solution(orders, course);

    return 0;
}