/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：


0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

示例1：
    输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    输出：2
    解释：
    两个元组如下：
    1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
    2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        /*考虑两次o(n^2)的遍历, 第一次遍历num1和num2, 将两两元素之和作为key放到unordered_map中, 它的value记录这个和出现的次数*/
        /*第二次遍历遍历num3和num4, 将0 - 两两元素之和去map中搜索, 若能搜索到, 则将对应的value加上, 最后总的count值为出现次数*/
        /*这里能够使用hash的原因在于不需要去除重复元素, 因为即使元素是重复的, 在数组中的下标是唯一的*/
        unordered_map<int, int> map;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                if (map.find(sum) == map.end()) {
                    map[sum] = 1;
                }
                else {
                    map[sum]++;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                int need_sum = -nums3[i] - nums4[j];
                auto it = map.find(need_sum);
                if (it != map.end()) {
                    count += it->second;
                }
            }
        }

        return count;
    }
};


int main() 
{


    return 0;
}

/*
* 运行时间180ms, 击败53.22％ c++用户
* 消耗内存24.08M, 击败67.00% c++用户
*/
