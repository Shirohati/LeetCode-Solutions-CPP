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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
题目：0083
给定一个已排序的链表的头 head， 删除所有重复的元素，使每个元素只出现一次 。返回已排序的链表 。
思路：
    略
总结：
    简单的基础链表操作
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* p=head;
        ListNode* next=p->next;
        while(next!=nullptr){
            if(next->val==p->val){
                next=next->next;
                p->next=next;
            }
            else{
                p=next;
                next=next->next;
                p->next=next;
            }
        }
        return head;
    }
};

int main() {
    Solution sol;
    return 0;
}