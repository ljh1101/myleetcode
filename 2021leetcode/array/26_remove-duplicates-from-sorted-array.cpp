
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定数组 nums = [1,1,2], 
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
！！！你不需要考虑数组中超出新长度后面的元素。

2021.1.15
*/

/*
*看了评论后，知道了有双指针写法,效率上来了，我不看答案打死我也想不出来。
*思想是不进行删除操作，而是把不符合条件的数移到后面，提高效率
*拿到这道题的想法就是怎么删除多余的数，然后后面的往前移，对数组直接操作时间复杂度会比较高，然后用来vector的erase函数，上当了
*利用双指针不用删除元素，而是后面数的直接替换前面的数。使慢指针指向无重复数据的最后一个，
*!慢指针之前的数据都是符合要求的，
*++j便为无重复数据数组长度。再后面的数据不需要考虑
*/
#include <vector>
#include <iterator>
using namespace std;
/*
执行用时：172 ms, 在所有 C++ 提交中击败了11.15%的用户
内存消耗：13.4 MB, 在所有 C++ 提交中击败了97.49%的用户
效率太低，不用迭代器效率依然底，初步判定erase函数是主要原因
*/
//时间复杂度：O（n），空间复杂度：O（1）
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 2)
        { //刚开始没加上这一段，直接报错  刚开始是判断等于零，其实用小于二逻辑才正确
            return nums.size();
        }
        vector<int>::iterator i = nums.begin() + 1;
        while (i != nums.end())
        {
            if (*i == *(i - 1))
            {
                nums.erase(i); //erase删除后指针不需要前移
            }
            else
            {
                i++;
            }
        }
        return nums.size();
    }
};

/*
执行用时：8 ms, 在所有 C++ 提交中击败了99.76%的用户
内存消耗：13.2 MB, 在所有 C++ 提交中击败了99.93%的用户
*/
//时间复杂度：O（n），空间复杂度：O（1）
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int s = nums.size();
        if (s < 2)
        {
            return s;
        }
        int j = 0;
        for (int i = 1; i < s; i++)
        {
            if (nums[i] != nums[j])//*这里是核心，j是双指针的慢指针，j之前的元素都是符合要求的
            {
                nums[++j] = nums[i];
            }
        }
        return ++j;
    }
};