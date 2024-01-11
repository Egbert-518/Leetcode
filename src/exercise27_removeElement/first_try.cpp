/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 注意不能使用额外的数组空间, 与上题不一样, 这里就不能再开辟一个vector了, 因为一是数组, 而是要求额外空间为O(1)

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                // 这个值是要被删除的
                for (size_t j = i; j < nums.size() - 1; j++) {
                    // 将后面的元素前移, 由于不需要考虑返回有效之外的元素, 因此一遍即可
                    nums[j] = nums[j + 1];
                }
                nums.pop_back();   // 最后一个不需要, 节省计算量
                i = i - 1; // 防止前移后的那个值也是需要删除的
            }
        }

        return nums.size();
    }

    int newRemoveElement(vector<int>& nums, int val) {
        /*学习双指针方法, 令两个快慢指针指向数组头, 逐渐后移, 若快指针指向要移除的元素, 慢指针在此时不移动*/
        int size = nums.size();
        auto slow_iter = nums.begin();
        auto fast_iter = nums.begin();

        while (fast_iter != nums.end())
        {
            if (*fast_iter == val) {
                size--;
                fast_iter++;
                continue;
            }
            else {
                *slow_iter = *fast_iter;
                slow_iter++;
                fast_iter++;
            }
            
        }
        return size;
    }
};

int main()
{   
    Solution solution;
    vector<int> nums = {3,2,2,3};
    int len = solution.removeElement(nums, 2);
    std::cout << len << std::endl;

    return 0;
} 

/*
* 执行时间32ms, 击败65.79%c++用户
* 内存消耗27.42M, 击败11.18%c++用户
*/