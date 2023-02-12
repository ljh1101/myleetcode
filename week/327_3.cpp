#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isItPossible(string word1, string word2)
    {
        vector<vector<int>> arr(26, vector<int>(2, 0));
        int num1 = 0, num2 = 0;
        for (auto w : word1) {
            if (arr[w - 'a'][0] == 0) {
                ++num1;
            }
            ++arr[w - 'a'][0];
        }
        for (auto w : word2) {
            if (arr[w - 'a'][1] == 0) {
                ++num2;
            }
            ++arr[w - 'a'][1];
        }
        if(abs(num1 - num2) == 0){
            return true;
        }
        else if (abs(num1 - num2) > 2) {
            return false;
        }
        else if (abs(num1 - num2) == 1) {
            for(auto v:arr){
                if(v[0]==0&&v[1]>1){
                    return true;
                }
                if(v[1]==0&&v[0]>1){
                    return true;
                }
            }
        }
        else if (abs(num1 - num2) == 2) {
            for(auto v:arr){
                if(v[0]==0&&v[1]>1){
                    return true;
                }
                if(v[1]==0&&v[0]>1){
                    return true;
                }
            }
        }
    }
};