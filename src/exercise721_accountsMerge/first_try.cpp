/*
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 按字符 ASCII 顺序排列 的邮箱地址。账户本身可以以 任意顺序 返回。

示例1:
    输入：accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
    输出：[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
    解释：
    第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。
    第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
    可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
    ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。


1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] 由英文字母组成
accounts[i][j] (for j > 0) 是有效的邮箱地址
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        /*哈希表存 邮箱: 下标, 遍历, 如果能在已有哈希表中得到相同的邮箱, 取对应下标的名字看是否同名(理论上相同邮箱不应该存在不同名的情况, 我们不考虑这一点), 添加到并查集中*/
        init(accounts.size());   // 初始化并查集
        unordered_map<string, int> map;
        for (int i = 0; i < accounts.size(); i++)
        {
            vector<int> correlated_idx;
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (map.find(accounts[i][j]) != map.end()) {
                    correlated_idx.push_back(map.find(accounts[i][j])->second);    // 能找到相同的邮箱, 说明这个人与之前的一个人相同, 但由于可能成环, 所以不能直接break, 即可能存在多个下标(属于同一个人, 后面需要加到并查集)
                }
            }
            if (!correlated_idx.empty()) {
                for (int j = 1; j < accounts[i].size(); j++)
                {
                    map[accounts[i][j]] = correlated_idx[0];    // 如果和之前对上了, 则用之前的, 默认第一个, 把剩下的加到并查集
                }
                // 将这个人与之前的加入到并查集
                for (int i = 1; i < correlated_idx.size(); i++)
                {
                    join(correlated_idx[0], correlated_idx[i]);    // 加到并查集, 暂时不需要对哈希表中的key做修改, 太耗时, 后面查找的时候用key的father就可以了
                }
            }
            else {
                for (int j = 1; j < accounts[i].size(); j++)
                {
                    map[accounts[i][j]] = i;   // 没和之前对上, 用现在的
                }
            }
        }

        vector<vector<string>> results(accounts.size(), vector<string>());
        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            if (results[find(iter->second)].empty()) {
                results[find(iter->second)].push_back(accounts[iter->second][0]);    // 如果是空的, 则先放名字
            }
            results[find(iter->second)].emplace_back(iter->first);    // 把邮箱放进去
        }

        vector<vector<string>> final_results;
        for (int i = 0; i < results.size(); i++)
        {
            if (!results[i].empty()) {
                sort(results[i].begin() + 1, results[i].end());    // 从第一个邮箱开始排序
                final_results.emplace_back(results[i]);
            }
        }
        return final_results;
    }

    void init(int n) {
        father.resize(n);
        for (int i = 0; i < n; i++)
        {
            father[i] = i;    // 并查集初始化
        }
    }

    int find(int u) {
        if (u == father[u]) {
            return u;
        }
        return father[u] = find(father[u]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        father[v] = u;
    }

private:
    vector<int> father;
};


int main()
{
    Solution solution;
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    solution.accountsMerge(accounts);
    return 0;
}

/*
* 运行时间65ms, 击败93.94% c++用户
* 消耗内存34.81M, 击败78.03% c++用户
*/
