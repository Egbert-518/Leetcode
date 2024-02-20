/*
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

示例 1：
    输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    解释：
    编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
    编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
    编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
    编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
    编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
    编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
    因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。

示例 2:
    输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
    输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]


1 <= people.length <= 2000
0 <= hi <= 10^6
0 <= ki < people.length
题目数据确保队列可以被重建
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
            return a.back() < b.back();   // 相同身高, k值小的排在前面
        }
        return a.front() > b.front();    // 否则身高高的排在前面
    }


    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*与之前分发糖果一样, 此时有两个维度, 不能同时考虑两个维度, 会顾此失彼, 那么应该优先考虑哪个维度呢*/
        /*如果考虑维度k, 则按照k排序后, 身高依然没有什么规律, 但若将身高按照从大到小排序后(相同的身高k小的排前面), 则进行插入时, 能够保证前面刚好有k个人大于自己的身高, 因为本节点之前的所有人身高都是大于自己的!*/

        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++)
        {
            int position = people[i].back();
            que.insert(que.begin() + position, people[i]);   // 起初担心比如在que为空时, 插入位置可能会不是0吗?不可能, 最高人前面一定不会有比它高的人, 所以第一个元素位置一定是0, 以此类推
        }

        return que;
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间80ms, 击败58.39％ c++用户
* 消耗内存28.45M, 击败5.04% c++用户
*/
