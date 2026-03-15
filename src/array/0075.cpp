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
题目：0075
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题
思路：
    利用三指针遍历
    指针条件：begin左边全是0，end右边全是2；所以i应该大于等于begin，小于等于end
总结：
    这次未考虑到的情况：
        1.循环终止条件未确立正确，一开始设置未i==end，代入发现应该再循环一位
        2.循环内出现了i变化的情况，未检验i是否会越界
 */
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n=nums.size();
            if(n==1)return;
            int begin=0,end=n-1;
            int i=0;
            while(i<=end){//i越过end，则终止，因为end右边一定全是2
                if(i<begin){
                    i++;
                    if(i>end)
                        return;//防止i越界
                }
                if(nums[i]!=1){
                    if(nums[i]==0){
                        swap(nums[i],nums[begin]);
                        begin++;
                    }
                    else{
                        swap(nums[i],nums[end]);
                        end--;
                    }
                }
                else{
                    i++;
                }
            }
        }
};

int main() {
    Solution sol;
    return 0;
}