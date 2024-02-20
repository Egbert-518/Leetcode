/*
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

示例1:
    输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    输出：3
    解释：长度最长的公共子数组是 [3,2,1] 。

示例 2：
    输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
    输出：5


1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /*dp[i][j]表示数组A中前i - 1个数据下, B中前j - 1个数据下, 最长的公共子数组长度*/
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int max_length = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                }
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
* 运行时间114ms, 击败73.57% c++用户
* 消耗内存85.85M, 击败21.98% c++用户
*/
