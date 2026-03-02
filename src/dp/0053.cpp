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
题目：0053
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
思路：状态:dp[i]，表示以nums[i]为结尾的所有子数组和的最大值
    边界：dp[0]=nums[0];
    可能性：是否抛弃前面的数组
    状态转移方程：dp[i-1]<0,则前面的无意义，因为考虑到前面的只会使得数组更小，dp[i]=nums[i];
            如果dp[i-1]>0, dp[i]=dp[i-1]+nums[i];
总结：这次定义的状态不代表最终解
 */
class Solution {
    public:
        
        int maxSubArray(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n);
            dp[0]=nums[0];
            int ans=dp[0];
            for(int i=1;i<n;i++){
                if(dp[i-1]<=0)dp[i]=nums[i];
                else dp[i]=nums[i]+dp[i-1];
                if(dp[i]>ans)ans=dp[i];
            }
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};
    cout<<sol.maxSubArray(a);
    return 0;
}