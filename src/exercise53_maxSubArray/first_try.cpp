/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

示例 1：
    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出：6
    解释：连续子数组 [4,-1,2,1] 的和最大，为6。

示例 2：
    输入：nums = [1]
    输出：1

示例 3：
    输入：nums = [5,4,-1,7,8]
    输出：23

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*思想是确定i位置的状态, 即以i位置为末尾的最大子数组和f(i), 其可以表示为max(nums[i], nums[i] + f(i - 1))*/
        if (nums.size() == 1)
            return nums[0];

        int fi_pre = 0;
        int max_sub_sum = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            fi_pre = nums[i] > nums[i] + fi_pre ? nums[i] : nums[i] + fi_pre;    // max_sub_sum存储的是f(i-1)
            if (fi_pre > max_sub_sum)
                max_sub_sum = fi_pre;
        }

        return max_sub_sum;
    }
};


int main() 
{
    Solution solution;
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    int max_sub_sum = solution.maxSubArray(nums);
    std::cout << max_sub_sum << std::endl;

    return 0;
}

/*
* 运行时间108ms, 击败21.74％ c++用户
* 消耗内存66.47M, 击败73.23% c++用户
*/
