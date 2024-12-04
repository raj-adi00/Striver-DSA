#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data1) {
        data = data1;
        next = nullptr;
    }
};
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;
        map<ListNode*, int> m;
        ListNode* temp = headA;
        while (temp) {
            m[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            if (m[temp] == 1) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB) {
        int n1 = 0, n2 = 0;
        ListNode* temp = headA;
        while (temp) {
            n1++;
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            n2++;
            temp = temp->next;
        }

        while (n1 > n2) {
            n1--;
            headA = headA->next;
        }
        while (n2 > n1) {
            n2--;
            headB = headB->next;
        }
        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

    ListNode* getIntersectionNode3(ListNode* headA, ListNode* headB) {
        ListNode *temp1 = headA, *temp2 = headB;
        if (!temp1 || !temp2) return nullptr;
        while (temp1 && temp2) {
            if (temp1 == temp2) return temp1;
            if (!temp1->next && !temp2->next) return nullptr;
            if (temp1->next)
                temp1 = temp1->next;
            else
                temp1 = headB;
            if (temp2->next)
                temp2 = temp2->next;
            else
                temp2 = headA;
        }
        return nullptr;
    }
};