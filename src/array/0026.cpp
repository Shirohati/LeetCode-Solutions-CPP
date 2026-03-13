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
题目：0026
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。
nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
判题标准:
系统会用下面的代码来测试你的题解:
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案
int k = removeDuplicates(nums); // 调用
assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。
思路：
    通过一个动态长度来读取正确的数
总结：
    可以优化为双指针，更直观，而且可以优化常数空间
 */
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size()<2)return 1;
            int leng=0;
            int pre=nums[0];
            for(int i=1;i+leng<nums.size();i++){
                if(nums[i+leng]==pre){
                    while(nums[i+leng]==pre){
                        leng++;
                        if(i+leng==nums.size())return nums.size()-leng+1;
                    }
                }
                nums[i]=nums[i+leng];
                pre=nums[i];
            }
            return nums.size()-leng;
        }
};

int main() {
    Solution sol;
    vector<int> n={1,1,2};
    sol.removeDuplicates(n);
    return 0;
}