/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。


示例1:
    输入：nums1 = [1,2,2,1], nums2 = [2,2]
    输出：[2]

示例2:
    输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出：[9,4]
    解释：[4,9] 也是可通过的

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]] = 0;   // 初始化这个key
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (map.find(nums2[i]) != map.end())
            {
                map[nums2[i]]++;
            }
        }

        vector<int> output;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second != 0) {
                output.push_back(it->first);
            }
        }
        return output;
    }
};

int main() 
{
    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };
    Solution solution;
    vector<int> output = solution.intersection(nums1, nums2);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << " ";
    }

    return 0;
}

/*
* 运行时间4ms, 击败87.71％ c++用户
* 消耗内存10.69M, 击败29.96% c++用户
*/
