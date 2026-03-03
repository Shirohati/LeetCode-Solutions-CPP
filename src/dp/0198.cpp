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
题目：0198
    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
思路：定状态：dp[i]，意为在选i的情况下dp的最大值；
    初始状态：dp[0]=nums[0],dp[1]=num[1];
    可能：选除相邻外的哪一个？最后一个选还是不选？
    状态转移方程：dp[i]=max(dp[0]~dp[i-2])+nums[i];
    优化：使用动态数组，只需要三个int，premax,pre,now，可使空间复杂度为o(1)
    时间复杂度o(n),空间复杂度o(1)
总结：简单的dp
    注：也可以用dp[i]表示有i个房屋下的最大值，但是复杂度一样，这里暂且不表
 */
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            int premax,pre,now;
            if(n==1)return nums[0];
            if(n==2)return max(nums[0],nums[1]);
            premax=nums[0];pre=nums[1];
            for(int i=2;i<n;i++){
                now=premax+nums[i];
                if(pre>premax)premax=pre;
                if(i!=n-1)pre=now;
            }
            return max(pre,now);
        }
};

int main() {
    Solution sol;
    vector<int>nums={2,9,3,3,9};
    cout<<sol.rob(nums);
    return 0;
}