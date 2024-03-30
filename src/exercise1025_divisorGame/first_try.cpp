/*
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字 n 。在每个玩家的回合，玩家需要执行以下操作：

选出任一 x，满足 0 < x < n 且 n % x == 0 。
用 n - x 替换黑板上的数字 n 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回 true 。假设两个玩家都以最佳状态参与游戏。

示例1:
    输入：n = 2
    输出：true
    解释：爱丽丝选择 1，鲍勃无法进行操作。

示例 2：
    输入：n = 3
    输出：false
    解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。


1 <= n <= 1000
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
    bool divisorGame(int n) {
        if (n == 1) {
            return false;
        }

        vector<bool> dp(n + 1, false);
        dp[2] = true;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0 && !dp[i - j]) {   // 只要有一个数字j满足上述条件, 且操作后的位置是输, 那么爱丽丝能赢, 否则即都是必胜状态, 操作后鲍勃赢
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间121ms, 击败96.40% c++用户
* 消耗内存84.55M, 击败35.14% c++用户
*/
