/*
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

示例 1：
    输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    输出：["JFK","MUC","LHR","SFO","SJC"]

示例 2：
    输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
    解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi 和 toi 由大写英文字母组成
fromi != toi
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 以下写法已经能够通过80/81例子了, 最后一个时间超出限制, 说明思路没问题, 考虑优化剪枝
class Solution {
public:
    struct cmp {
        bool operator() (std::pair<string, int> a, std::pair<string, int> b) {
            return a.first > b.first;
        }
    };

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        path.clear();
        path.emplace_back("JFK");
        results.clear();
        vector<bool> is_used(tickets.size(), false);
        backtracking(tickets, is_used);
        return results.front();
    }

    void backtracking(vector<vector<string>>& tickets, vector<bool>& is_used) {
        if (results.size() == 1) {
            return;    // 可能有多条路径, 当已有一条路径时, 直接return, 我的算法将保证这条路径一定是字典排序最小
        }
        if (path.size() == tickets.size() + 1) {
            // 说明所有票都走完
            results.emplace_back(path);
            return;
        }

        priority_queue<std::pair<string, int>, vector<std::pair<string, int>>, cmp> cur_goal_list;     // 原先只对string进行排序, 没有记录该string的位置, 导致有第二次遍历从而超时, 这次需要把对应位置放入
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i].front() == path.back() && !is_used[i]) {    // path存储上一次的终点, 如果上一次终点与票的起点相同且票未被使用, 把票的终点放入优先级队列
                cur_goal_list.push(std::pair<string, int>(tickets[i].back(), i));
            }
        }

        int size = cur_goal_list.size();
        for (int i = 0; i < size; i++)
        {
            std::pair<string, int> cur_goal = cur_goal_list.top();
            cur_goal_list.pop();
            if (!is_used[cur_goal.second]) {
                is_used[cur_goal.second] = true;
                path.emplace_back(cur_goal.first);
                backtracking(tickets, is_used);
                path.pop_back();
                is_used[cur_goal.second] = false;
            }
        }
    }

private:
    vector<string> path;
    vector<vector<string>> results;
};


struct cmp {
    bool operator() (std::pair<string, int> a, std::pair<string, int> b) {
        return a.first > b.first;
    }
};

int main()
{

    Solution solution;
    vector<vector<string>> tickets = { {"JFK","SFO"} ,{"JFK","ATL"},{"SFO","JFK"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"} };
    vector<string> results = solution.findItinerary(tickets);
    for (string result : results)
    {
        std::cout << result << std::endl;
    }

    return 0;
}

/*
* 超时
*
*/
