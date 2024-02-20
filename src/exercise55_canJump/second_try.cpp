/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

示例 1：
    输入：nums = [2,3,1,1,4]
    输出：true
    解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2:
    输入：nums = [3,2,1,0,4]
    输出：false
    解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。


1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
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
    bool canJump(vector<int>& nums) {
        /*动态规划, 每个节点维护当前能够跳到的最大距离, 看是否超过本节点位置*/
        if (nums.size() == 1) {
            return true;
        }

        int cur_max = nums.front();
        for (int i = 1; i < nums.size(); i++)
        {
            if (cur_max >= i) {
                // 表示能跳到, 看是否能够更新cur_max
                if (i + nums[i] > cur_max) {
                    cur_max = i + nums[i];
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间58ms, 击败26.13％ c++用户
* 消耗内存49.57M, 击败23.33% c++用户
*/
