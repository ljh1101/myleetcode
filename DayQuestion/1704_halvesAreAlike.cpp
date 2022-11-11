#include <string>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    bool halvesAreAlike(string s)
    {
        int len = s.size();
        int count = 0;
        unordered_set<char> comp = {'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U'};
        for (int i = 0, j = len / 2; i < len / 2 && j < len; i++, j++) {
            count += comp.count(s[i]);
            count -= comp.count(s[j]);
        }
        return count == 0;
    }
};