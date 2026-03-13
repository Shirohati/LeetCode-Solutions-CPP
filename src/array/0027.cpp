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
题目：0027
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。
用户评测：
评测机将使用以下代码测试您的解决方案：
int[] nums = [...]; // 输入数组
int val = ...; // 要移除的值
int[] expectedNums = [...]; // 长度正确的预期答案。
                            // 它以不等于 val 的值排序。
int k = removeElement(nums, val); // 调用你的实现
assert k == expectedNums.length;
sort(nums, 0, k); // 排序 nums 的前 k 个元素
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有的断言都通过，你的解决方案将会 通过。
思路：
    双指针
总结：
    注意边界处理
 */
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slow=0,fast=0;
            for(;fast<nums.size();slow++){
                while(nums[fast]==val){
                    fast++;
                    if(fast==nums.size())return slow;
                }
                nums[slow]=nums[fast];
                fast++;
            }
            return slow;
        }
    };

int main() {
    Solution sol;
    vector<int> n={1,2,3,8,7,3};
    cout<<sol.removeElement(n,3);
    return 0;
}