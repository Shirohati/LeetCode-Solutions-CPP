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
题目：0064
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
思路：状态：dp[i][j] 表示第i-1行第j-1列总和最小的状态
    边界：dp[0][0]=grid[0][0]
    可能：向下或向右
    状态转移方程：dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
    动态数组优化空间复杂度：在一个for(j:n)循环内，dp[j]=min(dp[j],dp[j-1])+grid[i][j];
                    这里，左边代表dp[j]代表当前(i,j)，右边dp[i]代表(i-1,j),dp[j-1]代表(i,j-1);
    时间复杂度o(mn)，空间复杂度o(n);
总结：简单的dp，但这次尝试了动态数组
 */
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size(),n=grid[0].size();
            vector<int> dp(n);
            dp[0]=grid[0][0];
            for(int i=1;i<n;i++)dp[i]+=dp[i-1]+grid[0][i];//初始化第一行
            for(int i=1;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j==0){
                        dp[j]=dp[j]+grid[i][j];
                    }
                    else {
                        dp[j]=min(dp[j],dp[j-1])+grid[i][j];
                    }
                }
            }
            return dp[n-1];
        }
};

int main() {
    Solution sol;
    vector<vector<int>>grid={{1,2,3},{4,5,6}};
    cout<<sol.minPathSum(grid);
    return 0;
}