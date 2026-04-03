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
题目：0206
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
思路：
    迭代思想：每前进一步需要逆转一个结点的方向，而每次逆转需要当前结点与上一个结点的指针，同时要保存下个一结点的指针防止断链，因此需要三个结点
总结：
    链表的题目，在思考时画图更好思考
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode* m=head;
        ListNode*p=nullptr;
        ListNode*q=head->next;
        while(1){
            m->next=p;
            if(q==nullptr)return m;
            p=m;
            m=q;
            q=q->next;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}