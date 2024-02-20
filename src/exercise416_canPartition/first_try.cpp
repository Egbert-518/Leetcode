/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例1:
    输入：nums = [1,5,11,5]
    输出：true
    解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
    输入：nums = [1,2,3,5]
    输出：false
    解释：数组不能分割成两个元素和相等的子集。

1 <= nums.length <= 200
1 <= nums[i] <= 100
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
    bool canPartition(vector<int>& nums) {
        /*抽象成一个背包问题, 背包的最大容量为sum / 2, 当然首先sum不是偶数可以直接返回false, 物品数量就是nums.size(), 物品重量就是nums[i], 若在sum / 2的最大容量下重量能达到sum / 2, 则返回true*/
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }

        sum = sum / 2;
        vector<int> dp(sum + 1, 0);    // 一维dp数组, dp[j]表示在背包重量为j时的最大收益
        // 开始遍历, 一维dp只能先遍历物品, 再反向遍历背包
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[sum] == sum) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 1, 5, 7, 5 };
    if (solution.canPartition(nums)) {
        std::cout << "yes\n";
    }
    else {
        std::cout << "no\n";
    }
    return 0;
}

/*
* 运行时间51ms, 击败93.52% c++用户
* 消耗内存12.78M, 击败53.08% c++用户
*/
