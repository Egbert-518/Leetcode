/*
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

示例 1：
    输入：points = [[10,16],[2,8],[1,6],[7,12]]
    输出：2
    解释：气球可以用2支箭来爆破:
    -在x = 6处射出箭，击破气球[2,8]和[1,6]。
    -在x = 11处发射箭，击破气球[10,16]和[7,12]。

示例 2:
    输入：points = [[1,2],[3,4],[5,6],[7,8]]
    输出：4
    解释：每个气球需要射出一支箭，总共需要4支箭。

示例 3：
    输入：points = [[1,2],[2,3],[3,4],[4,5]]
    输出：2
    解释：气球可以用2支箭来爆破:
    - 在x = 2处发射箭，击破气球[1,2]和[2,3]。
    - 在x = 4处射出箭，击破气球[3,4]和[4,5]。

1 <= points.length <= 10^5
points[i].length == 2
-2^31 <= xstart < xend <= 2^31 - 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a.front() == b.front()) {
            return a.back() < b.back();
        }
        return a.front() < b.front();
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        /*直观来说, 先对起止点从小到大排序, 以起点为主优先级, 终点为次优先级, 排序后, 遍历points, 对第一个的末点去查询有多少个起点在此之前, 可以用一根镖*/
        sort(points.begin(), points.end(), cmp);

        int num = 1, end_point = points.front().back();
        for (int i = 0; i < points.size(); i++)
        {
            end_point = min(end_point, points[i].back());    // 当前内部的最小范围
            if (points[i].front() > end_point) {
                end_point = points[i].back();    // 更新下一个最小范围
                num++;
            }
        }
        return num;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> points = { {9,12}, {1,10}, {4,11}, {8,12}, {3,9}, {6,9}, {6,7} };
    int arrow_num = solution.findMinArrowShots(points);
    std::cout << arrow_num << std::endl;
    return 0;
}

/*
* 运行时间2372ms, 击败5.03％ c++用户
* 消耗内存541.31M, 击败5.02% c++用户
*/
