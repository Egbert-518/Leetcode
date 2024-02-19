/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

示例 1：
    输入：nums = [2,3,1,1,4]
    输出：true
    解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2：
    输入：nums = [3,2,1,0,4]
    输出：false
    解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*从后往前遍历, 如果能存在到达末点的位置, 更新末点为该位置, 直到数组最前, 判断末点是否为0*/
        int end_pos = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] >= end_pos - i) {
                end_pos = i;
            }
        }
        if (end_pos == 0)
            return true;
        else
            return false;
    }
};


class NewSolution {
public:
    bool canJump(vector<int>& nums) {
        /*每个位置进行一次判断, 判断当前能够达到的最远距离, 如果中途这个最远距离不能够达到当前这个位置, 则false*/
        int cur_max_pos = nums[0] + 0;   // 当前能到达的最远距离是第一个位置的数值
        for (int i = 1; i < nums.size(); i++)
        {   
            if (cur_max_pos < i)
                return false;    // 如果当前能到达的最远距离到不了当前点, 则直接return
            if (nums[i] + i >= cur_max_pos)
                cur_max_pos = nums[i] + i;   // 更新当前能达到的最远距离
        }
        return true;
    }
};

int main() {

    NewSolution solution;
    vector<int> nums = { 3,0,8,2,0,0,1 };
    bool can_jump = solution.canJump(nums);
    if (can_jump) {
        std::cout << "can jump\n";
    }
    else {
        std::cout << "can not jump";
    }

    return 0;
}


