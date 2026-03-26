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
题目：0041
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
思路：
    注意到这题的有效取值在1到n+1之间，因为最终的答案一定是1到n+1，所以核心思路就是用原始数组的下标来表达信息；
    两种方法：
        1. 因为有效取值一定是正数，负号没有被利用到，所以我们使用负号来表示该下标所代表的值已经存在
        2. 直接移动数组中的元素到正确的位置    
总结：

 */
class Solution {
    public:
    //第一种方法
        int firstMissingPositive1(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]<=0)nums[i]=n+1; //将不是正数的元素剔除，这里只要满足大于n就可以
            }
            for(int i=0;i<n;i++){
                int a=abs(nums[i]);
                if(a<n+1){//属于范围内，进行标记
                    nums[a-1]=-abs(nums[a-1]);   //用abs保证该位置一定赋为负值；
                }
            }
            for(int i=0;i<n;i++){
                if(nums[i]>0)//该位置没有被标记过
                {
                    return i+1;
                }
            }
            return n+1; //所有位置都被标记了
        }
    //第二种方法
        int firstMissingPositive2(vector<int>& nums){
            int n=nums.size();
            int i=0;
            while(i<n){
                if(nums[i]<n+1&&nums[i]>0){//如果在范围内，尝试调整位置
                    if(nums[i]!=nums[nums[i]-1]){//如果不相同，则交换，i不加，检测换过来的数
                        swap(nums[i],nums[nums[i]-1]);
                    }
                    else{
                        i++;//如果相同，不用交换，检测下一个
                    }
                }
                else{
                    i++;//不在范围内，跳过，检测下一个
                }
            }
            for(int i=0;i<n;i++){
                if(nums[i]!=i+1)return i+1;
            }
            return n+1;
        }
    };

int main() {
    Solution sol;
    return 0;
}