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
题目：0021
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
思路：
    对两个链表进行整合，会出现断链的情况，用一个指针指向浮动链表
总结：
    指针再变化对原链表都没有影响，只有当指针所指的val或next变化时，才会影响到原来的链表
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        ListNode* head=nullptr;
        ListNode* q=nullptr;//定义q作为浮动的链表的首指针
        if(list1->val<list2->val){
            head=list1;
            q=list2;
        }
        else{
            head=list2;
            q=list1;
        }
        ListNode* p=head;
        while(p->next!=nullptr)
        {
            ListNode* temp=nullptr;
            if(p->next->val>q->val){
                temp=p->next;
                p->next=q;
                q=temp;
                p=p->next;
            }
            else{
                p=p->next;
            }
        }//每次循环开始时，q总是指向更大的点；所以一定是p->next先为NULL
        p->next=q;//当p->next==NULL时，直接合并剩余链表即可
        return head;
    }
};

int main() {
    Solution sol;
    return 0;
}