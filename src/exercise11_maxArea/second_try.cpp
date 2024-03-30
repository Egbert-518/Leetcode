/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。


示例 1：
    输入：[1,8,6,2,5,4,8,3,7]
    输出：49
    解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：
    输入：height = [1,1]
    输出：1

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

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
    int maxArea(vector<int>& height) {
        // 双指针, 总是移动数字小的那个指针
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right)    // 开区间, 重合时没意义
        {
            int cur_area = min(height[left], height[right]) * (right - left);   // 计算当前情况
            if (cur_area > max_area) {
                max_area = cur_area;
            }

            // 变动指针
            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return max_area;
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间71ms, 击败29.89% c++用户
* 消耗内存59.99M, 击败49.38% c++用户
*/
