/*
给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。

示例1:
    输入: [1,3,5,4,7]
    输出: 2
    解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。

示例 2：
    输入: [2,2,2,2,2]
    输出: 5
    解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。


1 <= nums.length <= 2000
-10^6 <= nums[i] <= 10^6
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
    int findNumberOfLIS(vector<int>& nums) {
        /*dp[j]记录以下标j结束的最长子序列长度*/
        vector<int> dp(nums.size(), 1);
        int max_len = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            int temp_max = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[j] > temp_max)
                {
                    temp_max = dp[j];
                }
            }
            dp[i] = temp_max + 1;
            if (dp[i] > max_len) {
                max_len = dp[i];
            }
        }

        if (max_len == 1) {
            return nums.size();
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == max_len) {
                count += traversal(dp, nums, i, max_len);
            }
        }
        return count;
    }

    int traversal(vector<int>& dp, vector<int>& nums, int max_idx, int max_len) {
        if (max_len == 1) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < max_idx; i++) {
            if (dp[i] == max_len - 1 && nums[i] < nums[max_idx]) {
                count += traversal(dp, nums, i, max_len - 1);
            }
        }
        return count;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 1,2,4,3,5,4,7,2 };
    solution.findNumberOfLIS(nums);
    return 0;
}

/*
* 通过, 但超出时间限制
*/
