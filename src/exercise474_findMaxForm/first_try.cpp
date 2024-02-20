/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例1:
    输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
    输出：4
    解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
    其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：
    输入：strs = ["10", "0", "1"], m = 1, n = 1
    输出：2
    解释：最大的子集是 {"0", "1"} ，所以答案是 2 。

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*这就相当于背包有两个属性, 每个物体也具有两个属性, 问能同时装得下两个属性的背包最多能装多少个物体*/
        vector<vector<int>> nums;
        for (string str : strs)
        {
            nums.emplace_back(calcNums(str));
        }

        // 容量有2个维度, 是否应该生成2个维度的背包? 一维背包通过滚动数组去掉了物体数量的维度, 但保留的是容量维度, 所以猜测大概是需要两维度
        // dp[i][j]表示第一个维度容量为i, 第二个维度容量为j的背包所能装的物体数量, dp[0][0] = 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int k = 0; k < nums.size(); k++)
        {
            for (int j = n; j >= nums[k].back(); j--)
            {
                for (int i = m; i >= nums[k].front(); i--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - nums[k].front()][j - nums[k].back()] + 1);
                }
            }

        }

        //for (int i = 0; i <= m; i++)
        //{
        //    for (int j = 0; j <= n; j++)
        //    {
        //        std::cout << dp[i][j] << " ";
        //    }
        //    std::cout << std::endl;
        //}

        return dp[m][n];
    }

    vector<int> calcNums(string& str) {

        int one = 0, zero = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0') {
                zero++;
            }
            else {
                one++;
            }
        }
        vector<int> num = { zero, one };
        return num;
    }
};


int main()
{
    Solution solution;
    vector<string> strs = { "11","01","11","01", "11","01", "11","01", "11","01" };
    int result = solution.findMaxForm(strs, 3, 3);
    //std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间100ms, 击败74.59% c++用户
* 消耗内存13.24M, 击败19.98% c++用户
*/
