#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool checkDistances(string s, vector<int>& distance)
    {
        unsigned int len = s.size();
        const int a = 97;
        vector<int> dis(26, -1);
        for (unsigned int i = 0; i < len; ++i) {
            unsigned int n = s[i] - a;
            if (dis[n] == -1)
                dis[n] = i;
            else if (distance[n] != i - dis[n] - 1)
                return false;
        }
        return true;
    }
};