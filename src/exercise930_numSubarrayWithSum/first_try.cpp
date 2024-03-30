/*
给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。

子数组 是数组的一段连续部分。

示例1:
    输入：nums = [1,0,1,0,1], goal = 2
    输出：4
    解释：
    有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]

示例 2：
    输入：nums = [0,0,0,0,0], goal = 0
    输出：15


1 <= nums.length <= 3 * 10^4
nums[i] 不是 0 就是 1
0 <= goal <= nums.length
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
    // 以下会超过时间限制
    int numSubarraysWithSumOld(vector<int>& nums, int goal) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix_sum[i + 1] = sum;    // 前缀和
        }

        int count = 0;
        for (int i = 1; i < prefix_sum.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (prefix_sum[i] - prefix_sum[j] == goal) {
                    count++;
                }
            }
        }

        return count;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 超时
*/
