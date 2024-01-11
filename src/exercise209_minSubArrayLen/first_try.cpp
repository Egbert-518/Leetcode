/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例1
    输入：target = 7, nums = [2,3,1,2,4,3]
    输出：2
    解释：子数组 [4,3] 是该条件下的长度最小的子数组。


1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*使用双指针法, 初始化左右指针在1, 2号位置(假设长度为1先判断), 求和, 若<target, 右移指针, 加上该值; 若>=target, 记录当前指针距离, 左移指针, 减去该值*/
        if (nums.size() == 1) {
            if (nums[0] >= target) 
                return 1;
            else 
                return 0;
        }

        // 排除了长度为1的情况
        int left_idx = 0, right_idx = 0;
        int cur_sum = nums[0];
        int cur_min_len = 1000000;
        while (right_idx < nums.size())
        {
            if (cur_sum >= target) {
                if (cur_min_len > right_idx - left_idx + 1) {
                    cur_min_len = right_idx - left_idx + 1;
                }
                cur_sum -= nums[left_idx];
                left_idx++;
                if (left_idx > right_idx) {   // 由于重合后的left++, 导致逻辑不对, 此时应该一同移动到下一位, 所以right++, 并更新cur_sum, 但其实这种情况下, 已经可以return 1了
                    // right_idx++;
                    // cur_sum += nums[right_idx];
                    return 1;
                }
            }
            else {
                 right_idx++;
                 if (right_idx == nums.size()) {
                    if (cur_min_len == 1000000)
                        return 0;   // 如果已经到最末位数
                    else 
                        return cur_min_len;
                 }
                 cur_sum += nums[right_idx];
            }
        }
        return cur_min_len;
    }
};

int main()
{   
    Solution solution;


    return 0;
} 

/*
* 执行时间32ms, 击败65.44%c++用户
* 内存消耗27.97M, 击败33.27%c++用户
*/