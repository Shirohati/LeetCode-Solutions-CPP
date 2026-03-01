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
题目：0010
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
返回一个布尔值，表示匹配是否覆盖整个输入字符串（而非部分）。

思路：状态f[i][u]，代表当前s字符串的前i个与p字符串的前u个字符是否匹配
    分类情况：当p[u-1]不等于'*'时 有两种可能，即当前匹配上或没有匹配上
            当p[u-1]等于'*'时  有三种可能，即*匹配了0次，1次，多次
    状态转移方程：当p[u-1]不等于'*'时，f[i][u]=f[i-1][u-1]&&(s[i-1]==p[u-1]||p[u-1]='.');（对字符串来说，i-1表示第i个字符,注意这里与f的下标含义区别）
                当p[u-1]等于'*'，*可能匹配0次或1次，多次
                        当s[i-1]=p[u-2]    f[i][u]=f[i-1][u]||f[i][u-2];这行代码的含义是，既然f[i-1][u]匹配成功，那么再多匹配一个也可以（这是*已经匹配多次的情况下）
                                                    那么*为第一次匹配上呢？也就是说s[i-2]似乎没有与*匹配上，这时f[i-1][u]似乎必然等于flase了
                                                    但是，根据下面的方程可知，这时可以算作'*'匹配到了空白，所以也算是匹配上了（这时*第一次匹配上的情况）
                                                    还有一种情况，例如s="ab",p="abb*"，这里虽然s[1]==p[2]，但是没有新的字符串与之对应了，所以是匹配到0次
                                                    因此需要加上"||f[i][u-2]“(这是没有匹配上的情况)
                        else f[i][u]=f[i][u-2];这行代码的含义是，如果'*'匹配了零次，那么相当于把这对字符串撇去，
                                                这时，如果f[i][u-2]为true，也就是说当前s字符串与撇去后的p字符串匹配，就与撇去前的字符串匹配，
                                                因为可以匹配零次，不影响结果（这时*第零次匹配上的情况）
                至此，所有可能下的状态转移方程都书写完毕。
    边界情况：都为空字符串时，f[0][0]=1，当空匹配到"*"时，f[0][j]=f[0][j-2]；
总结：
    dp的核心步骤：找状态，列可能，写方程，定边界
 */
class Solution {
    public:
    bool exam(char a,char b)
    {
        if(a==b||b=='.')return true;
        else return false;
    }
    bool isMatch(string s, string p) {
        int snum=s.size(),pnum=p.size();
        vector<vector<bool>> f(snum + 1, vector<bool>(pnum + 1, false));
        f[0][0]=1;
        for(int j=1;j<pnum+1;j++){
            if(p[j-1]=='*')f[0][j]=f[0][j-2];
            else f[0][j]=0;
        }
        for(int i=1;i<snum+1;i++){
            for(int u=1;u<pnum+1;u++){
                if(p[u-1]=='*')
                {
                    if(exam(s[i-1],p[u-2]))f[i][u]=f[i-1][u]||f[i][u-2];
                    else f[i][u]=f[i][u-2];
                }
                else{
                    f[i][u]=f[i-1][u-1]&&exam(s[i-1],p[u-1]);
                }
            }
        }
        return f[snum][pnum];
    }
};
    


int main() {
    Solution sol;
    string s,p;
    s="aab";
    p="c*a*b";
    bool ans=sol.isMatch(s,p);
    if(ans)cout <<"true";
    else cout<<"false";
    return 0;
}