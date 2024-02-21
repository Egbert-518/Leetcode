/*
给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

示例1:
    输入: nums = [1,2,1]
    输出: [2,-1,2]
    解释: 第一个 1 的下一个更大的数是 2；
    数字 2 找不到下一个更大的数；
    第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

示例 2：
    输入: nums = [1,2,3,4,3]
    输出: [2,3,4,-1,4]


1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*循环数组, 那只要将nums复制一遍放到尾部即可, 这样还查找不到的话那么就返回-1*/
        vector<int> results(nums.size(), -1);
        stack<int> st;

        for (int i = 0; i < 2 * nums.size(); i++)
        {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()])
            {
                if (results[st.top()] == -1) {
                    results[st.top()] = nums[i % nums.size()];   // 如果第一次找到过了, 防止第二次再写入
                }
                st.pop();
            }
            st.push(i % nums.size());
        }

        return results;

    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 1, 2, 1 };
    solution.nextGreaterElements(nums);
    return 0;
}

/*
* 运行时间30ms, 击败51.65% c++用户
* 消耗内存25.97M, 击败24.45% c++用户
*/
