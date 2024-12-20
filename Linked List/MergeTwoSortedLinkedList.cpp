/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1 = list1, *head2 = list2;
        if (!head1) return head2;
        if (!head2) return head1;
        ListNode* head = nullptr;
        if (head1->val <= head2->val) {
            head = new ListNode(head1->val);
            head1 = head1->next;
        } else {
            head = new ListNode(head2->val);
            head2 = head2->next;
        }
        ListNode* temp = head;
        while (head1 && head2) {
            ListNode* curr;
            if (head1->val <= head2->val) {
                curr = new ListNode(head1->val);
                head1 = head1->next;
            } else {
                curr = new ListNode(head2->val);
                head2 = head2->next;
            }
            temp->next = curr;
            temp = temp->next;
        }
        while (head1) {
            ListNode* curr = new ListNode(head1->val);
            temp->next = curr;
            temp = temp->next;
            head1 = head1->next;
        }
        while (head2) {
            ListNode* curr = new ListNode(head2->val);
            temp->next = curr;
            temp = temp->next;
            head2 = head2->next;
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2 {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1 = list1, *head2 = list2;
        if (!head1) return head2;
        if (!head2) return head1;
        ListNode* head = nullptr;
        head = new ListNode(-1);
        ListNode* temp = head;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        if (head1) temp->next = head1;
        if (head2) temp->next = head2;
        return head->next;
    }
};