/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：
    输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
    输出：[[1,6],[8,10],[15,18]]
    解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
    输入：intervals = [[1,4],[4,5]]
    输出：[[1,5]]
    解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。


1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a.front() < b.front();
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> results;
        int start_point = intervals.front().front(), end_point = intervals.front().back();
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].front() <= end_point) {
                end_point = max(intervals[i].back(), end_point);
            }
            else {
                vector<int> result = { start_point, end_point };
                results.emplace_back(result);
                start_point = intervals[i].front();
                end_point = intervals[i].back();
            }
        }

        vector<int> result = { start_point, end_point };
        results.emplace_back(result);

        return results;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vector<vector<int>> results = solution.merge(intervals);
    for (vector<int> result : results)
    {
        std::cout << result.front() << " " << result.back() << std::endl;
    }
    return 0;
}

/*
* 运行时间133ms, 击败11.27% c++用户
* 消耗内存50.98M, 击败4.99% c++用户
*/
