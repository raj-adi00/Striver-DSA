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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = n;
        if (!head || cnt == 0) return head;
        ListNode* temp = head;
        while (cnt && temp) {
            cnt--;
            temp = temp->next;
        }
        if (cnt != 0) return head;
        if (!temp) {
            ListNode* deleteNode = head;
            head = head->next;
            delete (deleteNode);
            return head;
        }
        ListNode* slow = head;
        while (temp->next) {
            temp = temp->next;
            slow = slow->next;
        }
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete (deleteNode);
        return head;
    }
};