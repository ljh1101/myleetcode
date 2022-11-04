#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string s1, s2;
        for (auto w1 : word1) {
            s1.append(w1);
        }
        for (auto w2 : word2) {
            s2.append(w2);
        }
        return s1 == s2;
    }
};