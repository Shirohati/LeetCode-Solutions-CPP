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
题目：0063
给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。

网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。

返回机器人能够到达右下角的不同路径数量。

测试用例保证答案小于等于 2 * 10^9。
思路：同0062.cpp，只需加入障碍物判定即可
    时间复杂度o(mn),空间复杂度o(mn);
总结：较为简单的dp
 */
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& grid) {
            int m=grid.size();//行
            int n=grid[0].size();//列
            if(m==1&&n==1)return -grid[0][0]+1;
            vector<vector<int>> dp(m,vector<int>(n,0));
            dp[0][0]=-grid[0][0]+1;
            for(int i=1;i<m;i++){
                if(grid[i][0])dp[i][0]=0;
                else dp[i][0]=dp[i-1][0];
            }
            for(int j=1;j<n;j++){
                if(grid[0][j])dp[0][j]=0;
                else dp[0][j]=dp[0][j-1];
            }
            if(m==1||n==1)return dp[m-1][n-1];
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(grid[i][j])dp[i][j]=0;
                    else dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
};
int main() {
    Solution sol;
    vector<vector<int>> test(1,vector<int>(1));
    test[0][0]=1;
    cout<<sol.uniquePathsWithObstacles(test);
    return 0;
}