/*
给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例1:
    输入：nums = [1,1,1,1,1], target = 3
    输出：5
    解释：一共有 5 种方法让最终目标和为 3 。
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3

示例 2：
    输入：nums = [1], target = 1
    输出：1

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*假设取正号的数字和为pos, 取负号的数字和为neg, 则有pos + neg = sum(nums), pos - neg = target, 所以pos = (sum + target) / 2, 为一固定值*/
        /*意味着要从nums看能够取一些数字使它们的和为pos, 可以用回溯法, 但是由于长度最大为20, 应该会超时*/
        /*用背包, 容量为pos, dp[j]表示容量为j的背包有多少种方法填满, dp[0]=1, 且dp[j]=求和(dp[j-nums[i]])*/
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (abs(target) > sum) {
            return 0;
        }
        if ((sum + target) % 2 == 1) {
            return 0;    // (sum + target) / 2非整, 说明sum与target奇偶性不同, 但改变某个数字符号必定不改变奇偶性, 故这也不可能, 同时防止了整数除法向下取整的情况
        }

        sum = (sum + target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 1, 5, 7, 5 };

    return 0;
}

/*
* 运行时间4ms, 击败88.70% c++用户
* 消耗内存10.73M, 击败36.14% c++用户
*/
