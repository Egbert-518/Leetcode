/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

示例 1：
    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出：6
    解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2:
    输入：nums = [1]
    输出：1

示例 3：
    输入：nums = [5,4,-1,7,8]
    输出：23

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*贪心, 从头开始求和, 当和为负数时抛弃, 下一个从0开始计算, 过程中记录最大值*/
        int cur_max = INT32_MIN;
        int cur_sum = 0;
        for (int num : nums)
        {
            cur_sum = cur_sum + num;
            if (cur_sum > cur_max) {
                cur_max = cur_sum;
            }
            if (cur_sum < 0) {
                cur_sum = 0;   // 重置
            }
        }
        return cur_sum;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间81ms, 击败80.73％ c++用户
* 消耗内存68.53M, 击败37.81% c++用户
*/
