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
题目：0229
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素
思路：
    仍是投票法，也想到了用两个山头，但是没想到要同时换掉两个山头的人
总结：
    对于超过n/m次的元素，只有对剩下分成m-1组的元素同时都消灭一个才能保证胜出（或平局）
    相比n/2的情况，多了些边界处理和输出检测
 */
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n=nums.size();
            vector<int> flag={0,0};
            vector<int> count={0,0};
            for(int i=0;i<n;i++){
                if(nums[i]==flag[0]||nums[i]==flag[1]){
                    if(nums[i]==flag[0]){
                        count[0]++;
                    }
                    else{
                        count[1]++;
                    }
                }
                else{
                    if(!count[0]||!count[1]){
                        if(!count[0]){
                            flag[0]=nums[i];
                            count[0]++;
                        }
                        else{
                            flag[1]=nums[i];
                            count[1]++;
                        }
                    }
                    else{
                        count[0]--;
                        count[1]--;
                    }
                }
            }
            int num1=0,num2=0;
            for(int i=0;i<n;i++){
                if(nums[i]==flag[0])num1++;
                if(nums[i]==flag[1])num2++;
            }
            if(flag[1]==flag[0]){
                flag.pop_back();
                return flag;
            }
            vector<int>ans;
            if(num1>n/3)ans.push_back(flag[0]);
            if(num2>n/3)ans.push_back(flag[1]);
            return ans;
        }
    };

int main() {
    Solution sol;
    return 0;
}