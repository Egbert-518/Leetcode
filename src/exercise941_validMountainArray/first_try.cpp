/*
给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
    arr.length >= 3
    在 0 < i < arr.length - 1 条件下，存在 i 使得：
        arr[0] < arr[1] < ... arr[i-1] < arr[i]
        arr[i] > arr[i+1] > ... > arr[arr.length - 1]

示例1:
    输入：arr = [2,1]
    输出：false

示例 2：
    输入：arr = [3,5,5]
    输出：false

示例 3：
    输入：arr = [0,3,2,1]
    输出：true

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^4
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
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[1] <= arr[0]) {
            return false;
        }

        bool up = true;
        for (int i = 1; i < arr.size(); i++)
        {
            if (up) {
                if (arr[i] > arr[i - 1]) {
                    continue;
                }
                else if (arr[i] == arr[i - 1]) {
                    return false;
                }
                else {
                    up = false;
                }
            }
            else {
                if (arr[i] < arr[i - 1]) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }

        if (up) {
            return false;    // 防止一直上山
        }
        else {
            return true;
        }

    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间18ms, 击败80.77% c++用户
* 消耗内存24.24M, 击败21.50% c++用户
*/
