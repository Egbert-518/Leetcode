/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

示例 1：
    输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
    输出：[3,3,5,5,6,7]
    解释：
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*用双端队列, 队列中只保持单调递减*/
        vector<int> results;
        deque<int> monotonic_queue;

        // 初始化前k位
        for (int i = 0; i < k; i++)
        {
            if (monotonic_queue.empty()) {
                monotonic_queue.push_back(nums[i]);
            }
            else {
                while (!monotonic_queue.empty())
                {
                    int back = monotonic_queue.back();
                    if (nums[i] > back) {     // 这里不应取等号, 同样大的也需要入队
                        monotonic_queue.pop_back();
                    }
                    else {
                        break;
                    }
                }
                monotonic_queue.push_back(nums[i]);
            }
        }

        for (int i = 0; i < nums.size() - k; i++)
        {
            results.push_back(monotonic_queue.front());   // 添加当前滑窗里的最大值
            // 开始滑动窗口
            if (nums[i] == monotonic_queue.front()) {
                // 如果要移除的元素与当前最大值相同
                monotonic_queue.pop_front();
            }
            while (!monotonic_queue.empty())
            {
                int back = monotonic_queue.back();
                if (nums[i + k] > back) {
                    monotonic_queue.pop_back();
                }
                else {
                    break;
                }
            }
            monotonic_queue.push_back(nums[i + k]);
        }
        // 最后的一组没有被计算
        results.push_back(monotonic_queue.front());
        return results;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<int> results = solution.maxSlidingWindow(nums, 3);
    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
    return 0;
}

/*
* 运行时间260ms, 击败38.87% c++用户
* 消耗内存132.11M, 击败36.17% c++用户
*/
