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
题目：0238
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
思路：状态：dp[i]表示以i为尾数的前缀和
            pd[i]表示以i为头数的后缀和
    初始条件：
    可能：边界处理
    状态转移方程：dp[i]=dp[i-1]*nums;
    时间复杂度o(n),空间复杂度o(n)
总结：
    前缀和后缀和问题
 */
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n=nums.size();
            vector<int>ans(n);
            if(n==1){
                ans[0]=nums[0];
                return ans;
            }
            vector<int>dp(n);
            vector<int>pd(n);
            dp[0]=nums[0];
            pd[n-1]=nums[n-1];
            for(int i=1;i<n;i++){
                dp[i]=dp[i-1]*nums[i];
            }
            for(int i=n-2;i>=0;i--){
                pd[i]=pd[i+1]*nums[i];
            }
            ans[0]=pd[1];
            ans[n-1]=dp[n-2];
            for(int i=1;i<n-1;i++){
                ans[i]=dp[i-1]*pd[i+1];
            }
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> nums={3};
    vector<int> ans(nums.size());
    ans=sol.productExceptSelf(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<',';
    }
    return 0;
}