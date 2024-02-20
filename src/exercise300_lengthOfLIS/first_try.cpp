/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例1:
    输入：nums = [10,9,2,5,3,7,101,18]
    输出：4
    解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
    输入：nums = [0,1,0,3,2,3]
    输出：4

示例 3：
    输入：nums = [7,7,7,7,7,7,7]
    输出：1

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
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
    int lengthOfLIS(vector<int>& nums) {
        /*dp[i]表示在i及之前并以nums[i]结尾的最长子序列长度, 它并不一定是i之前最长的子序列长度, 因此需要记录每个dp[i]中的最大值, 而不是返回dp[n]*/
        vector<int> dp(nums.size(), 1);
        int max_length = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);    // j处的子序列一定以nums[j]结尾
                }
            }
            if (dp[i] > max_length) {
                max_length = dp[i];
            }
        }

        return max_length;
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间88ms, 击败65.98% c++用户
* 消耗内存12.70M, 击败5.83% c++用户
*/
