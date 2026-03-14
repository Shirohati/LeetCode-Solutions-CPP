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
题目：0283
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。
思路：
    双指针
总结：
 */
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int slow=0,fast=0;
            while(fast<nums.size()){
                if(nums[slow]==0){
                    while(nums[fast]!=0){
                        fast++;
                        if(fast==nums.size())return; 
                    }
                    swap(nums[slow],nums[fast]);
                }
                slow++;
                if(fast<slow)fast++;
            }
            return;
        }
};

int main() {
    Solution sol;
    return 0;
}