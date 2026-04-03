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
题目：0203
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
思路：
    通过next指针检测
总结：
    应该注意到删除的过程其实也是next指针前进一位的过程，因此此时不应该更新p的值为p->next
 */


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return nullptr;
        while(head!=nullptr){
            if(head->val==val)head=head->next;
            else break;
        }
        ListNode* p=head;
        while(1){
            if(p==nullptr||p->next==nullptr)return head;
            if(p->next->val==val){
                p->next=p->next->next;
            }
            else p=p->next;
        }
    }
};
int main(){
    return 0;
}