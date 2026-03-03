#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
using namespace std;


/**
题目：0062
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
思路：状态：dp[i][j];表示到达第i-1行第j-1列的路径条数
    边界：dp[i][0]=dp[0][j]=dp[0][0]=1;
    可能：向下移动或向右移动
    状态转移方程：dp[i][j]=dp[i-1][j]+dp[i][j-1];
    时间复杂度o(mn)，空间复杂度o(mn)
总结：简单的动态规划
优化：用滚动数组代替dp数组，优化空间复杂度
 */
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if(m==1||n==1)return 1;
            vector<vector<int>> dp(m,vector<int>(n));
            for(int i=0;i<m;i++)dp[i][0]=1;
            for(int j=0;j<n;j++)dp[0][j]=1;
            for(int i=1;i<m;i++)
            {
                for(int j=1;j<n;j++){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
};

int main() {
    Solution sol;
    cout<<sol.uniquePaths(4,5);
    return 0;
}