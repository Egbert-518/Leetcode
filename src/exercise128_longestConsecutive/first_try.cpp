/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。


示例 1：
    输入：nums = [100,4,200,1,3,2]
    输出：4
    解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
    输入：nums = [0,3,7,2,5,8,4,6,0,1]
    输出：9

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> set;
        for (int num : nums)
        {
            set.insert(num);
        }

        int longest_len = 1;
        for (const int& num : set)
        {
            if (set.count(num - 1) == 0) {
                // 说明前面没有数字, 可以统计, 否则, 前面有数字, 肯定不是最大长度, 统计会浪费时间
                int cur_num = num + 1;
                while (set.count(cur_num) != 0)
                {
                    cur_num++;
                }
                if (cur_num - num > longest_len) {
                    longest_len = cur_num - num;
                }
            }
        }

        return longest_len;
    }
};

int main()
{
    // Solution solution;

    return 0;
}

/*
* 运行时间133ms, 击败61.63% c++用户
* 消耗内存72.42M, 击败30.48% c++用户
*/
