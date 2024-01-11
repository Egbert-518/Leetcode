/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例1
    输入：nums = [-4,-1,0,3,10]
    输出：[0,1,9,16,100]
    解释：平方后，数组变为 [16,1,0,9,100]
    排序后，数组变为 [0,1,9,16,100]

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums 已按 非递减顺序 排序
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*最简单的思想就是, 对nums逐元素平方, 在排序, 时间复杂度在o(nlogn + n)*/
        /*考虑使用双指针法, 在内存使用上应该会高一些, 但o(n)*/

        vector<int> result(nums.size(), 0);
        int left_idx = 0, right_idx = nums.size() - 1, cur_pos = nums.size() - 1;
        while (cur_pos >= 0)
        {
            int left = nums[left_idx] * nums[left_idx];
            int right = nums[right_idx] * nums[right_idx];

            if (left > right) {
                result[cur_pos] = left;
                cur_pos--;
                left_idx++;
            }
            else {
                result[cur_pos] = right;
                cur_pos--;
                right_idx--;
            }
        }
        return result;
    }
};

int main()
{   
    Solution solution;


    return 0;
} 

/*
* 执行时间28ms, 击败58.85%c++用户
* 内存消耗25.62M, 击败64.64%c++用户
*/