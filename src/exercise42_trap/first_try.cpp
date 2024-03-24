/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

示例 2：
    输入：height = [4,2,0,3,2,5]
    输出：9

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        /*虽然是道困难标识题目, 但感觉只要找到每个元素的右边第一个大于等于它的元素值和下标, 再统计这之间的能够装水数量即可(如果找不到, 应该找小于该值的最大值所在的位置)*/
        vector<int> results(height.size(), -1);   // 首先找第一个大于等于其元素的下标, -1表示找不到
        stack<int> st;

        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[i] >= height[st.top()])    // 相等也是可以的
            {
                results[st.top()] = i;   // 记录下标即可
                st.pop();
            }
            st.push(i);
        }

        // 此时, results中为-1的表示该元素右边没有比它更高的, 需要把这些值更新为它右边元素中的最高值下标
        int cur_max = height[height.size() - 1];
        int cur_idx = height.size() - 1;
        for (int i = height.size() - 2; i >= 0; i--)
        {
            if (results[i] == -1) {
                results[i] = cur_idx;
            }

            if (height[i] > cur_max) {
                cur_max = height[i];
                cur_idx = i;
            }
        }

        int count = 0;
        for (int i = 0; i < results.size(); )
        {
            if (results[i] == -1) {
                // 说明这个点右边没有比它更高的元素
                break;
            }
            else {
                // 右边有, 则我们需要统计从i到results[i]中可以装多少
                int limit = min(height[i], height[results[i]]);  // 确定上限
                for (int j = i + 1; j <= results[i] - 1; j++)
                {
                    count += (limit - height[j]);
                }

                i = results[i];   // 下一次从这个下标开始
            }
        }

        return count;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间15ms, 击败46.20% c++用户
* 消耗内存22.83M, 击败5.08% c++用户
*/
