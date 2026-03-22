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
题目：0169
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
思路：
    投票法：假设一堆人增强山头，如果每次遇到相同队伍的就把队伍容量加一，遇到不同队伍的就进行一换一，然后山头上的队伍人数减一；
        如果山头队伍人数归零，就让新来的占领山头，队伍旗帜改变；因为多数元素比其他所有的人都多，所以最后一定是多数元素胜出，返回最终旗帜
总结：
    很巧妙也很新颖的算法

 */
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n=nums.size();
            if(!n)return nums[0];
            int flag=nums[0];
            int count=1;
            for(int i=1;i<n;i++){
                if(nums[i]==flag)count++;
                else{
                    if(!count){
                        flag=nums[i];
                        count++;
                    }
                    else{
                        count--;
                    }
                }
            }
            return flag;
        }
    };

int main() {
    Solution sol;
    return 0;
}