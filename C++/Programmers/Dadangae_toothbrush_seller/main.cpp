#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> income;

void updateProfit(string name, int money)
{
    if (name == "-")
        return;
    int interest = money * 0.1;
    income[name] += (money - interest);
    if (interest < 1)
        return;
    updateProfit(parent[name], interest);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        updateProfit(seller[i], amount[i] * 100);
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(income[enroll[i]]);
    }

    return answer;
}

int main()
{
    vector<string> enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};

    vector<int> ans = solution(enroll, referral, seller, amount);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}