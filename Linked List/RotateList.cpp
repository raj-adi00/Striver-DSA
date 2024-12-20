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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* tail = head;
        if (!head || k == 0) return head;
        while (tail) {
            n++;
            tail = tail->next;
        }
        k = k % n;
        if (k == 0) return head;
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        ListNode* curr = head;
        while (temp->next) {
            temp = temp->next;
            curr = curr->next;
        }
        ListNode* nextPart = curr->next;
        curr->next = nullptr;
        temp->next = head;
        return nextPart;
    }
};