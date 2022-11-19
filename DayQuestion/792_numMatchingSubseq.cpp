#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        vector<vector<int>> v(26);
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a'].emplace_back(i);
        }
        for (string word : words)
        {
            int pos = -1;
            bool flag = true;
            for (char w : word)
            {
                auto it = upper_bound(v[w - 'a'].begin(), v[w - 'a'].end(), pos);
                if (it == v[w - 'a'].end())
                {
                    flag = false;
                    break;
                }
                pos = *it;
            }
            if (flag)
            {
                count++;
            }
        }
        return count;
    }
};