/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

2021.1.14
*/

/*
*这道题一开始一直不会做，主要原因是不会map的用法和map的key存放数组的内容这一小技巧
*思路：遍历数组，如果能在map中找到target-num[i]则判定为找到结果，结果分别是i和map[target-nums[i]]，
*若在map中未找到target-num[i]，则把当前访问的值加入map（数组的内容作为map的关键字，数组的下标作为map的值）。
*/
//复杂度分析：时间复杂度：O（n），空间复杂度：O（n）（哈希表）

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> aws(2, -1);
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mymap.find(target - nums[i]) != mymap.end())
            {                                     //查找的是map的key
                aws[0] = mymap[target - nums[i]]; //存入向量
                aws[1] = i;
                return aws;
            }
            mymap[nums[i]] = i; //*困扰我好久的地方，这里是数组的内容作为map的关键字，数组下标作为map的值，内容与下标反过来了
        }
        return aws; //可以直接return{}，学到了
    }
};
