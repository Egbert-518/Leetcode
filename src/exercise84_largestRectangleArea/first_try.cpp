/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

示例1:
    输入：heights = [2,1,5,6,2,3]
    输出：10
    解释：最大的矩形为图中红色区域，面积为 10

示例 2：
    输入： heights = [2,4]
    输出： 4


n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*思想是对于每个位置的矩形, 计算出左边第一个小于它高度和右边第一个小于它高度的位置, 然后以该位置矩形高度乘以宽*/
        /*第一个高度, 考虑用单调栈, 代码随想录应该有单次遍历方法, 我这里先用两次遍历分别得到左边和右边的坐标*/
        vector<int> left_min_index(heights.size(), -1);   // 如果没有找到, 那说明左边没有更低的, 那应该找下标0
        vector<int> right_min_index(heights.size(), heights.size());   // 同样, 如果右边没有更低的, 应该找下标heights.size() - 1
        stack<int> st;

        for (int i = 0; i < heights.size(); i++)
        {
            // 先算右边第一个小于的下标
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                right_min_index[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();    // 清空栈
        }

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                left_min_index[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int cur_area = (right_min_index[i] - left_min_index[i] - 1) * heights[i];
            if (cur_area > max_area) {
                max_area = cur_area;
            }
        }

        return max_area;
    }
};


int main()
{
    Solution solution;
    vector<int> height = { 1,2,3,4,5 };
    int result = solution.largestRectangleArea(height);
    std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间128ms, 击败53.79% c++用户
* 消耗内存85.54M, 击败5.00% c++用户
*/
