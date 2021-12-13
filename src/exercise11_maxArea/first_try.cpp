/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

// 超出时间限制 o(n^2)
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int n = height.size();
//        int maxCapacity = 0;
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < i; j++)
//            {
//                int capacity = min(height[i], height[j]) * (i - j);
//                maxCapacity = capacity > maxCapacity ? capacity : maxCapacity;
//            }
//        }
//        return maxCapacity;
//    }
//};

class Solution {
public:
	int maxArea(vector<int>& height) {
		auto begin = height.begin();
		auto end = height.end() - 1;
		int maxCapacity = min(*end, *begin) * (end - begin);

		while (begin != end)
		{
			if (*begin <= *end)
				begin++;
			else
				end--;
			int capacity = min(*end, *begin) * (end - begin);
			maxCapacity = capacity > maxCapacity ? capacity : maxCapacity;
		}
		return maxCapacity;
	}
};


/*
* 执行用时：80 ms, 在所有 C++ 提交中击败了38.73%的用户
* 内存消耗：57.6MB, 在所有 C++ 提交中击败了74.14%的用户
* 通过测试用例：60 / 60
*/
