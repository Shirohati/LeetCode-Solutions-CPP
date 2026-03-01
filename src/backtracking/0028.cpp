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
题目：0028
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

思路：使用回溯法，剪枝,判断三次，加左括号，加右括号，到达终点；
总结：
 */
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& res, string cur, int open, int close, int max) {
        if (cur.length() == max * 2) {
            res.push_back(cur);
            return;
        }
        if (open < max) {
            backtrack(res, cur + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(res, cur + ")", open, close + 1, max);
        }
    }
};
int main() {
        Solution sol;
        vector<string>ans;
        
        return 0;
}