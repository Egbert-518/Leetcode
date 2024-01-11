/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例1:
    输入: nums = [-1,0,3,5,9,12], target = 9
    输出: 4
    解释: 9 出现在 nums 中并且下标为 4

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*mysearch中是没有学习前的写法, 比较拉跨, 根据学习知道应该如何去确定等号该不该取, mid是否需要-1等*/
        /*
           一般二分法有两种写法, 我习惯于左闭右闭区间, 则判断left与right大小时, 需要写等号, 因为left == right有意义, 而更新mid时需要写mid - 1, 因为nums[mid]一定与target不同, 下次不需要再计算
        */
        int low_idx = 0;
        int high_idx = nums.size() - 1;

        while (low_idx <= high_idx) 
        {
            int mid_idx = int((low_idx + high_idx) / 2);
            if (nums[mid_idx] == target) {
                return mid_idx;
            }
            else if (nums[mid_idx] > target) {
                high_idx = mid_idx - 1;
            }
            else {
                low_idx = mid_idx + 1;
            }
        }
        return -1;
    }
    int mysearch(vector<int>& nums, int target) {
        /*题目的主要目的是希望我们用二分查找, 来练习一下吧*/
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            }
            else {
                return -1;
            }
        }
        
        int low_idx = 0;
        int high_idx = nums.size() - 1;

        while (low_idx < high_idx) 
        {
            if (low_idx == high_idx - 1) {    // 避免死循环, 以及nums的size()为1或2的情况
                if (nums[low_idx] == target) {
                    return low_idx;
                }
                else if (nums[high_idx] == target) {
                    return high_idx;
                }
                else {
                    return -1;
                }
            }
            int mid_idx = int((low_idx + high_idx) / 2);
            if (nums[mid_idx] == target) {
                return mid_idx;
            }
            
            if (nums[mid_idx] > target) {
                high_idx = mid_idx;
            }
            else {
                low_idx = mid_idx;
            }
        }

        return -1;
    }
};


int main()
{   
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    int idx = solution.search(nums, 2);
    std::cout << idx << std::endl;

    return 0;
} 

/*
* 执行时间32ms, 击败65.79%c++用户
* 内存消耗27.42M, 击败11.18%c++用户
*/