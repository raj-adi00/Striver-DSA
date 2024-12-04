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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while (temp) {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (!s.empty()) {
            if (temp->val != (s.top())) return false;
            temp = temp->next;
            s.pop();
        }
        return true;
    }


    ListNode* reverse(ListNode* head) {
        if (!head || head->next == nullptr) return head;
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }


    bool isPalindrome2(ListNode* head) {
        if (!head || head->next == nullptr) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode *first = head, *second = newHead;
        while (second) {
            if (first->val != second->val) {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    }
};