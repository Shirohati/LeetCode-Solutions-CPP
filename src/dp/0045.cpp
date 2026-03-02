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
题目：0045
给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：

0 <= j <= nums[i] 且 i + j < n
返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
思路：状态：dp[i]，表示到i的最小跳跃次数
    初始值：dp[0]=0;
    可能性：有u种选择，其中1 <= u <= nums[i] 且 i + u < n
    状态转移方程：dp[i]=min(for(u:nums) nums[u])+1 当u可以到i时；
    算法时间复杂度 o（n^2)
总结：比较好想的动态规划
原代码：
class Solution {
    public:
        int jump(vector<int>& nums) {
            vector<int> dp(nums.size(),10001);
            dp[0]=0;
            for(int i=0;i<nums.size();i++)
            {
                for(int u=1;u<=nums[i]&&i+u<nums.size();u++){
                    if(dp[i+u]>dp[i]+1)dp[i+u]=dp[i]+1;
                }
            }
            return dp[nums.size()-1];
        }
};
优化：可以分析到题目具有贪心性质，因此每次选能到达更远性质的点来更新dp数组
    优化后时间复杂度 o(n)
 */
class Solution {
    public:
        int min(int a,int b){
            if(a<b)return a;
            else return b;
        }
        int jump(vector<int>& nums) {
            vector<int> dp(nums.size(),10001);
            dp[0]=0;
            int max=0;
            for(int i=0;i<nums.size();i++)
            {
                int nowmax=i+nums[i];
                if(nowmax>max){//如果当前可以到达更远
                    for(int u=max+1;u<=min(nowmax,nums.size()-1);u++)//更新新到达地方的dp数组
                    {
                        dp[u]=dp[i]+1;
                    }
                    max=nowmax;
                }
                if(max>nums.size()-1)break;
            }
            return dp[nums.size()-1];
        }
};

int main() {
    Solution sol;
    vector<int> a;
    a.push_back(1);
    cout<<sol.jump(a);
    return 0;
}