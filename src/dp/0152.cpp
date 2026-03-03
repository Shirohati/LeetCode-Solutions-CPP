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
题目：0152
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
测试用例的答案是一个 32-位 整数。
请注意，一个只包含一个元素的数组的乘积是这个元素的值
思路：状态：dp[i]表示以i结尾的最大乘积，fdp[i]表示以i结尾的最大负数值乘积
                fdp数组旨在记录负数大的情况，如果fdp变为正数，则更新fdp
                因为nums[i]必为整数，因此除0外，乘上后绝对值总不小于原绝对值
    初始值：因为要保证dp为正，fdp为负，所以在遇到第一个负值时，才算完成初始化，每次遇到0要重新判定一次
    可能性：正变正，负号变正，正变负，变0；
    状态转移方程：当nums[i]为0时，dp[i]=0;
            其他，dp[i]=dp[i-1]*nums[i];fdp[i]=fdp[i-1]*nums[i];
                        当nums[i]<0时，swap(dp[i],fdp[i-1])；
    时间复杂度o(n),空间复杂度o(1);
总结：比较特殊的dp题，好歹做出来了，但是对0的更新用到了if语句，没有纳入到状态转移方程里面，所以代码比较冗杂
优化方向：优化代码结构
 */
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n=nums.size();
            if(n==1)return nums[0];
            int dp=1,fdp=1;
            int begin=0;
            int ans=INT_MIN;
            int flag=1;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    flag=1;//意味着dp和fdp都大于等于0；
                }
                if(dp==0)dp=nums[i];
                else dp*=nums[i];
                if(fdp==0)fdp=nums[i];
                else fdp*=nums[i];
                if(nums[i]<0){
                    if(flag){
                        dp=0;
                        flag=0;
                    }
                    else{
                        swap(dp,fdp);
                    }
                }
                ans=max(dp,ans);
            }
            return ans;
        }
};

int main() {
    Solution sol;
    vector<int> nums={2,-10,3,5,-3,-2};
    cout<<sol.maxProduct(nums);
    return 0;
}