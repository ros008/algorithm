class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m[s[i]] = 1;
            }
            else
            {
                m[s[i]]++;
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (m[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    };
}

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int ch[26] = {0};
        for (char c : s)
            ch[c - 'a']++;
        int i = 0;
        for (char c : s)
        {
            if (ch[c - 'a'] == 1)
                return i;
            i++;
        }
        return -1;
    }
};