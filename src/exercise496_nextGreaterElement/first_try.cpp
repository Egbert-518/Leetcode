/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

示例1:
    输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
    输出：[-1,3,-1]
    解释：nums1 中每个值的下一个更大元素如下所述：
    - 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
    - 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
    - 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。

示例 2：
    输入：nums1 = [2,4], nums2 = [1,2,3,4].
    输出：[3,-1]
    解释：nums1 中每个值的下一个更大元素如下所述：
    - 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
    - 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。


1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 10^4
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中

进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*通过两层for循环的o(mn)复杂度可以得到结果, 考虑用单调栈实现o(m + n)*/
        unordered_map<int, int> umap;    // 因为nums1中的元素一定不重复, 所以创建umap, 添加是一个o(m)的复杂度, 后续查找为o(1)
        for (int i = 0; i < nums1.size(); i++)
        {
            umap[nums1[i]] = i;     // 记录该元素的下标    
        }

        vector<int> results(nums1.size(), -1);   // 最终要返回结果的初始化
        stack<int> st;

        for (int i = 0; i < nums2.size(); i++)
        {
            while (!st.empty() && nums2[i] > nums2[st.top()])
            {
                if (umap.find(nums2[st.top()]) != umap.end()) {
                    // 如果能找到当前栈顶的元素, 现在要插入进来的元素大于它
                    results[umap[nums2[st.top()]]] = nums2[i];    // 记录该元素
                }
                st.pop();   // 不管找到与否, 都要pop
            }

            st.push(i);
        }

        return results;
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*
* 运行时间4ms, 击败83.21% c++用户
* 消耗内存11.86M, 击败14.40% c++用户
*/
