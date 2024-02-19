/*
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
0 <= j <= nums[i]
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

示例 1：
    输入: nums = [2,3,1,1,4]
    输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        /*目前的思路是, 从最后一个点开始, 查找最远的能一步跳到这个点的点, 然后更新这个点为末点, 跳跃次数 + 1, 直到起始点*/
        if (nums.size() == 1)
            return 0;

        int cur_end = nums.size() - 1;
        int jump_cnt = 0;
        while (cur_end > 0)   // 如果没有走回起点
        {
            // 现在找对于当前cur_end来说, 能够一步到此的最远的一个点
            int min_idx = cur_end;
            for (int i = cur_end - 1; i >= 0; i--)
            {
                if (nums[i] >= cur_end - i) {
                    // 如果这个点的数值能够超过或不小于cur_end之间的距离, 说明能到达
                    min_idx = i;   // 由于i递减, 一定是这个更小
                }
            }
            cur_end = min_idx;    // 更新末点到能够一步跳到的最远点
            jump_cnt++;           // 跳跃次数 + 1
        }

        return jump_cnt;
    }
};

/*
    官方的解法1与我的思路基本相同, 只是它是顺向的, 也就是从前往后遍历, 找到第一个能够跳跃到末点的点, 然后将这个点作为新的末点
    但上述这种方法的时间复杂度在o(n^2), 解法2提供了一种o(n)的思想, 在这里不用代码实现, 但说一下想法
    依然是维护当前能够到达的最远距离, 遍历每个点, 更新当前能够到达的最远距离, 如果当前点的位置到达了这个最远距离边界, 则将跳跃次数+1
*/

int main() {

    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    int jump_num = solution.jump(nums);
    std::cout << jump_num << std::endl;
    return 0;
}

/*
* 运行时间64ms, 击败19.34％ c++用户
* 消耗内存16.54M, 击败49.64% c++用户
*/
