/*
给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。

序号代表了一个元素有多大。序号编号的规则如下：
    序号从 1 开始编号。
    一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
    每个数字的序号都应该尽可能地小。

示例1:
    输入：arr = [40,10,20,30]
    输出：[4,1,2,3]
    解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。

示例 2：
    输入：arr = [100,100,100]
    输出：[1,1,1]
    解释：所有元素有相同的序号。

示例 3：
    输入：arr = [37,12,28,9,100,56,80,5,12]
    输出：[5,3,4,2,8,6,7,1,3]

0 <= arr.length <= 10^5
-10^9 <= arr[i] <= 10^9
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
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) {
            return {};
        }

        vector<std::pair<int, int>> arr_pair(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            arr_pair[i] = { arr[i], i };    // 数值, 索引
        }
        sort(arr_pair.begin(), arr_pair.end(), cmp);
        vector<int> result(arr.size(), 0);
        result[arr_pair[0].second] = 1;

        int same_count = 0;
        for (int i = 1; i < arr_pair.size(); i++)
        {
            if (arr_pair[i].first == arr_pair[i - 1].first) {
                same_count++;
            }
            result[arr_pair[i].second] = i + 1 - same_count;
        }

        return result;
    }

    static bool cmp(std::pair<int, int> a, std::pair<int, int>b) {
        return a.first < b.first;   // 从小到大排, 不需要考虑索引排序
    }
};

int main()
{
    Solution solution;
    vector<int> arr = { 40, 30, 10, 20 };
    solution.arrayRankTransform(arr);

    return 0;
}

/*
* 运行时间45ms, 击败99.59% c++用户
* 消耗内存34.41M, 击败89.75% c++用户
*/
