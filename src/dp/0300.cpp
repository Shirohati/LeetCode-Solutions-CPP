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
题目：0300
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
思路：状态:dp[i]，表示以nums[i]结尾的最长递增子序列长度
    初始值：dp[0]=1;
    可能性：选哪个作为前缀？
    状态转移方程 dp[i]=max(dp[j])+1;    0 <= j < i-1,且nums[i]>nums[j];
    时间复杂度o(n^2)，空间复杂度o(n);
总结： 仍是状态非答案型dp
初始代码：
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<int>dp(n,1);
            int max=1;
            for(int i=1;i<n;i++){
                int premax=1,flag=0;
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i]&&dp[j]>=premax)
                    {
                        premax=dp[j];
                        flag=1;//判定是否添加了前缀
                    }
                }
                if(flag)dp[i]=premax+1;
                else dp[i]=1;
                if(max<dp[i])max=dp[i];
            }
            return max;
        }
};
 */


/**
优化：采用贪心算法和二分查找优化
    优化方向：寻找maxdp[j]的过程
思路：当递增子序列长度一样时，末尾数字更小的总是最优
实现：通过一个数组d，d[i]代表当前状态下递增子序列长度为i时最小的末尾数字
                易得d数组是递增数组（二分查找的必要条件），而且整个d数组则是当前情况下最优的递增子序列
    d[i]的更新过程：设len=d.length()-1
        当nums[i]>d[len]，则最长子序列长度加一,nums[i]作为末尾数字
        否则，寻找第一个小于nums[i]的d[j]，使得d[j+1]=nums[i]；
                        这个分支的逻辑是：如果新数不能使序列长度加一，就用它能否优化d数组，更新为长度为j+1的最长子序列的末尾数字，
                        因为它比原来的末尾数字更小，满足贪心策略
             寻找方式采用二分查找；
 */
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int len = 1, n = (int)nums.size();
            if (n == 0) {
                return 0;
            }
            vector<int> d(n + 1, 0);
            d[len] = nums[0];
            for (int i = 1; i < n; ++i) {
                if (nums[i] > d[len]) {
                    d[++len] = nums[i];
                } else {
                    int l = 1, r = len, pos = 0;
                    while (l <= r) {
                        int mid = (l + r) >> 1;
                        if (d[mid] < nums[i]) {
                            pos = mid;
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    d[pos + 1] = nums[i];
                }
            }
            return len;
        }
};
    
int main() {
    Solution sol;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<sol.lengthOfLIS(nums);
    return 0;
}