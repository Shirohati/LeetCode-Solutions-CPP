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
题目：0221
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
思路：
    状态：dp[i][j][u]表示以i，j为右下顶点的u*u大小的正方形
    边界：dp[i][j][1]=matrix[i][j]
    可能性：穷举？
    状态转移方程:dp[i][j][u]=dp[i-1][j-1][u-1]&&dp[i-1][j][u-1]&&dp[i][j-1][u-1]&&dp[i][j][u-1]
    时间复杂度o(mn*min(m,n)) 空间复杂度o(mn*min(m,n));
总结：简单思路的动态规划，但是复杂度太高了
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            vector<vector<vector<char>>> dp(m,vector<vector<char>>(n,vector<char>(min(m,n)+1)));
            int ans=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    dp[i][j][1]=matrix[i][j]-'0';
                    if(matrix[i][j]-'0'==1)ans=1;
                }
            }
            for(int u=2;u<=min(m,n);u++){
                for(int i=0;i+u-1<m;i++){
                    for(int j=0;j+u-1<n;j++){
                        dp[i+u-1][j+u-1][u]=dp[i-1+u-1][j-1+u-1][u-1]&&dp[i-1+u-1][j+u-1][u-1]&&dp[i+u-1][j-1+u-1][u-1]&&dp[i+u-1][j+u-1][u-1];
                        if(dp[i+u-1][j+u-1][u]==1)ans=u;
                    }
                }
            }
            return ans*ans;
        }
};
 */
/*
优化方向：通过优化状态定义来优化动态规划算法
    状态定义：dp[i][j]定义为以i,j为右下顶点的最大正方形边长；
    状态转移方程：dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
总结：这种方法通过更有信息量的定义，把多出来的一维空间u定义到了dp值里，从而实现了空间和时间上的优化，本质是提高了dp数组的利用效率
*/
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            if (matrix.size() == 0 || matrix[0].size() == 0) {
                return 0;
            }
            int maxSide = 0;
            int rows = matrix.size(), columns = matrix[0].size();
            vector<vector<int>> dp(rows, vector<int>(columns));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (matrix[i][j] == '1') {
                        if (i == 0 || j == 0) {
                            dp[i][j] = 1;
                        } else {
                            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                        }
                        maxSide = max(maxSide, dp[i][j]);
                    }
                }
            }
            int maxSquare = maxSide * maxSide;
            return maxSquare;
        }
};


int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'0'}
    };
    cout << sol.maximalSquare(matrix);
    return 0;
}