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
    ListNode* rec(ListNode* head) {
        if (!head || head->next == nullptr) return head;
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = rec(head);
        if (!head || head->next == nullptr) return head;
        head->next = nullptr;
        return temp;
    }
};