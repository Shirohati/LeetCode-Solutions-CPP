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
题目：0008
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。

函数 myAtoi(string s) 的算法如下：

空格：读入字符串并丢弃无用的前导空格（" "）
符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
返回整数作为最终结果。

思路：一点一点模拟
总结：看着很简单的题，其实各种问题麻烦到让人头大
    1.何时开始读取到数字？
        这个决定了能否正确读取到正负号，也是耗时最久的问题
        解决方式：利用num_flag，确保确认正负号的操作只运行一次，并且当这个数是数字时，i要回退一位；
    2.边界问题
        决定了越界能否正确输出
        解决方式：利用多个if语句
收获：写之前一定要动脑子，有了全局构思后再写，不然要改很长时间
 */
/*
更好的写法：
要点：1.通过一个start变量解决了问题1，即检测符号的操作有且只有一次，并且一定是空格之后的第一次（这个我没意识到）
      2.通过sign来记录符号，并且通过num+=sign*s[i]的操作使得全程不用分类讨论符号问题，巧妙
class Solution {
    public int myAtoi(String s) {
        int sign = 1;
        int res = 0;
        int m = s.length();
        int i = 0;
        while(i < m && s.charAt(i)==' '){
            i++;
        }
        int start = i;
        for(; i < m; i++){
            char c = s.charAt(i);
            if(i==start && c=='+'){
                sign = 1;
            }else if(i==start && c=='-'){
                sign = -1;
            }else if(Character.isDigit(c)){
                int num = c-'0';
                if(res > Integer.MAX_VALUE/10 || (res == Integer.MAX_VALUE/10&&num>Integer.MAX_VALUE%10)){
                    return Integer.MAX_VALUE;
                }

                if(res < Integer.MIN_VALUE/10 || (res == Integer.MIN_VALUE/10&&-num<Integer.MIN_VALUE%10)){
                    return Integer.MIN_VALUE;
                }
                res = res*10+sign*num;
            }else{
                break;
            }
        }
        return res;
    }
}
*/
class Solution {
    public:
        int myAtoi(string s) {
            int i=0;
            //检测空格，无空格时退出
            while(s[i]==' '){
                i++;
            }
            int num_flag=0;//是否读取到数字
            int f_flag=0;
            int num=0;
            for(i;i<s.size();i++)
            {
                if(!num_flag)
                {
                    num_flag=1;
                    if(s[i]=='-')f_flag=1;
                    else if(s[i]=='+')f_flag=0;
                    else{
                        if(isdigit(s[i]))i--;
                        else break;
                    }
                }
                else{
                    if(!isdigit(s[i])){//不是数字直接终止
                        break;
                    }
                    else{
                        if(num==0)num+=(s[i]-'0');//首位数为0的情况下
                        else{
                            //进行边界处理，三种情况：1.num*10后越界，2.num*10后不越界，且加上s[i]也不越界，3.加上s[i]后越界
                            //其中，1，3越界，可以直接退出循环；
                            if(num>214748364){//*10越界
                                if(f_flag)num=INT_MIN;
                                else num=INT_MAX;
                                break;
                            }
                            else{//*10不越界
                                num*=10;
                                if(f_flag){
                                    if(num>=2147483640&&s[i]-'0'>7){
                                        num=INT_MIN;
                                        break;
                                    }
                                    else{
                                        num+=(s[i]-'0');
                                    }
                                }
                                if(!f_flag){
                                    if(num>=2147483640&&s[i]-'0'>6){
                                        num=INT_MAX;
                                        break;
                                    }
                                    else{
                                        num+=(s[i]-'0');
                                    }
                                }   
                            }
                            
                        }
                    }
                }
            }
            if(num==INT_MIN){
                return num;
            }
            else{
                if(f_flag)return -num;
                else return num;
            }
        }
};

int main() {
    Solution sol;
    string s;
    s="     +-2147484647dsfa";
    int num=sol.myAtoi(s);
    cout<<num;
    return 0;
}