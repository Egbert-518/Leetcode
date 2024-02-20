/*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

示例1:
    输入：nums = [1,3,5,4,7]
    输出：3
    解释：最长连续递增序列是 [1,3,5], 长度为3。
    尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。

示例 2：
    输入：nums = [2,2,2,2,2]
    输出：1
    解释：最长连续递增序列是 [2], 长度为1。


1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
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
    int findLengthOfLCIS(vector<int>& nums) {
        /*相比于非连续子序列, 此处dp[i]表示前i个数据中以nums[i]结尾的最长连续子序列即可, 并且只需要判断nums[i]与nums[i - 1]大小即可*/
        vector<int> dp(nums.size(), 1);
        int max_length = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
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
* 运行时间12ms, 击败26.98% c++用户
* 消耗内存13.24M, 击败12.58% c++用户
*/
