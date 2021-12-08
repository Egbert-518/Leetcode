/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count_1 = 0, count_2 = 0;
        vector<int> totalNums;
        for (int i = 0; i < nums1.size() + nums2.size() && count_1 < nums1.size() && count_2 < nums2.size(); i++)
        {
            if (nums1[count_1] <= nums2[count_2])
            {
                totalNums.emplace_back(nums1[count_1++]);
            }
            else
            {
                totalNums.emplace_back(nums2[count_2++]);
            }
        }
        if (count_1 == nums1.size())
        {
            for (int i = count_2; i < nums2.size(); i++)
            {
                totalNums.emplace_back(nums2[i]);
            }
        }
        else if (count_2 == nums2.size())
        {
            for (int i = count_1; i < nums1.size(); i++)
            {
                totalNums.emplace_back(nums1[i]);
            }
        }
        return (totalNums[int((totalNums.size() - 1) / 2)] + totalNums[int(totalNums.size() / 2)]) * 0.5;
    }
};

/*
* 执行用时：16 ms, 在所有 C++ 提交中击败了97.99%的用户
* 内存消耗：87.6 MB, 在所有 C++ 提交中击败了15.32%的用户
* 通过测试用例：2094 / 2094
*/